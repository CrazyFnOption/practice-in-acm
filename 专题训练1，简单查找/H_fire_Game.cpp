#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

#define inf 0x3f3f3f3f

int n,m;
const int maxn = 15;
char map[maxn][maxn];
int vis[maxn][maxn];

struct point{
    int x,y,pos;
    point (){}
    point (int a,int b,int c) : x(a),y(b),pos(c) {}
    point move(int i) {
        point tmp(x,y,pos);
        switch (i){
            case 0:{
                tmp.x = x + 1;
                break;
            }
            case 1:
            {
                tmp.x = x - 1;
                break;
            }
            case 2:
            {
                tmp.y = y + 1;
                break;
            }
            case 3:
            {
                tmp.y = y - 1;
                break;
            }
        }
        tmp.pos++;
        return tmp;
    }
};


int bfs(point a,point b) 
{
    queue<point> q;
    point now,next;
    q.push(a);
    q.push(b);
    memset(vis,inf,sizeof vis);
    vis[a.x][a.y] = 0;
    vis[b.x][b.y] = 0;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            next = now.move(i);
            if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m 
            && map[next.x][next.y] == '#' && vis[next.x][next.y] == inf) {
                vis[next.x][next.y] = next.pos;
                q.push(next);
            }
        }
    }
    int res = 0;
    for (int i = 0 ;i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '#') 
                res = max(res,vis[i][j]);
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    int Case = 1;
    while (T--) {
        cin >> n >> m;
        int cnt = 0;
        getchar();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j ++) {
                cin >> map[i][j];
                if (map[i][j] == '#') {
                    cnt ++;
                }
            }
        }

        if (cnt <= 2) {
            cout << "Case " << Case++ << ": " << 0 << endl;
            continue;
        }

        int res = inf;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == '#') {
                    for (int l = 0; l < n; l++) {
                        for (int k = 0; k < m; k++) {
                            if (l < i && k <= j) continue;
                            if (map[l][k] == '#'){
                                point p1(i,j,0);
                                point p2(l,k,0);
                                int ans = bfs(p1,p2);
                                res = min(ans,res);
                            }
                        }
                    }
                }
            }
        }
        if (cnt == inf)
            cout << "Case " << Case++ << ": " << -1 << endl;
            else
                cout << "Case " << Case++ << ": " << cnt << endl;
    }
}