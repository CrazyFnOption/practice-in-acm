#include<iostream>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

#define inf 0x3f3f3f3f

struct point {
    int x,y,step;
    point() {}
    point (int a,int b,int c) : x(a),y(b), step(c) {}
    point move(int i) {
        point tmp(x, y, step);
        switch (i)
        {
        case 0:
        {
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
        tmp.step++;
        return tmp;
    }
};

const int maxn = 1010;

int m,n;

char map[maxn][maxn];
bool vis[maxn][maxn];
int _time[maxn][maxn];

queue<point> q_fire;
queue<point> q_joe;

void bfs_fire() {
    point now, next;
    while (!q_fire.empty()) {
        now = q_fire.front();
        q_fire.pop();
        for (int i = 0; i < 4 ; i++) {
            next = now.move(i);
            if (next.x >= 0 && next.y >= 0 && next.x < m && next.y < n 
                && _time[next.x][next.y] > next.step && (map[next.x][next.y] == '.' || map[next.x][next.y] == 'J')) {
                    q_fire.push(next);
                    _time[next.x][next.y] = next.step;
                }
        }
    }
}

bool is_ok(int x,int y) {
    return (x == 0 || y == 0 || x == m - 1 || y == n - 1);
}

int bfs_joe() {
    point now,next;
    while (!q_joe.empty()) {
        now = q_joe.front();
        q_joe.pop();
        if (is_ok(now.x,now.y)) return now.step + 1;
        for (int i = 0; i < 4; i ++) {
            next = now.move(i);
            if (next.x >= 0 && next.y >= 0 && next.x < m && next.y < n 
            && !vis[next.x][next.y] && map[next.x][next.y] == '.' && next.step < _time[next.x][next.y]){
                q_joe.push(next);
                vis[next.x][next.y] = true;
            }
        }
    }
    return 0;
}
void clear()
{
    memset(vis, false, sizeof(vis));
    while (!q_fire.empty())
        q_fire.pop();
    while (!q_joe.empty())
        q_joe.pop();
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        clear();
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
                _time[i][j] = inf;
                if (map[i][j] == 'J') {
                    q_joe.push(point (i,j,0));
                    vis[i][j] = true;
                }
                else if (map[i][j] == 'F') {
                    q_fire.push(point(i,j,0));
                }
            }
            getchar();
        }
        bfs_fire();
        int t = bfs_joe();
        if (t) cout << t << endl;
        else
            cout << "IMPOSSIBLE" << endl;
        
    }
}