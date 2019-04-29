#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n,m,k;
const int maxn = 105;
char map[maxn][maxn];

struct pos{
    int x;
    int y;
    pos(){is_a = false;};
    pos(int a,int b) :x(a),y(b){}
    bool is_a ;
}E[5];


pos beg;
int Min;
int cnt,total;
bool vis[maxn][maxn];

bool check(const pos &p) {
    for (int i = 1; i <= k;i++) {
        if (E[i].x == p.x && E[i].y == p.y) {
            E[i].is_a = true;
            return true;
        }
    }
    return false;
}

bool fun() {
    for (int i = 1; i <= k; i++) {
        if (E[i].is_a == false) return false;
    }
    return true;
}

void dfs(const pos & p) {
    if (p.x < 1 || p.x > n || p.y < 1 || p.y > m || vis[p.x][p.y] || map[p.x][p.y] == '#') return;
    if (cnt == k && fun()) {
        Min  = min(Min,total);
        return ;
    }
    if (check(p)) {
        cnt ++;
        memset(vis,false,sizeof vis);
    }
    total++;
    cout << p.x << "  " << p.y << endl;
    vis[p.x][p.y] = true;
    dfs(pos(p.x - 1, p.y));
    dfs(pos(p.x + 1, p.y));
    dfs(pos(p.x, p.y + 1));
    dfs(pos(p.x, p.y - 1));
    return ;
}

int main()
{
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j];
                if (map[i][j] =='@') {
                    beg.x = i;
                    beg.y = j;
                }
            }
            
        }

        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> E[i].x >> E[i].y;
        }
        Min = 0x3f3f3f3f;
        cnt = total = 0;
        memset(vis,false,sizeof vis);
        dfs(beg);
        if (Min == 0x3f3f3f3f) cout << -1 << endl;
        else cout << Min << endl;
    }
    return 0;
}