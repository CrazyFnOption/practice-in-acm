#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int n,k;
char map[10][10];
bool vis[10];
int total,cnt;

void dfs(int s) {
    if (s > n) return ;
    if (cnt == k) {
        total++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && map[s][i] == '#') {
            vis[i] = true;
            cnt++;
            dfs(s + 1);
            cnt--;
            vis[i] = false;
        }
    }
    dfs(s + 1);
}
int res;
int _dfs(int s) {
    if (s > n) return total;
    if (cnt == k) {
        total ++;
        return total;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && map[s][i] == '#')
        {
            vis[i] = true;
            cnt++;
            res += _dfs(s + 1);
            cnt--;
            vis[i] = false;
        }
    }
    return  res += _dfs(s + 1);
}

int main()
{
    while (cin >> n >> k) {
        if (n == -1 && k == -1) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n ;j++) {
                cin >> map[i][j];
            }
            getchar();
        }
        total = 0;
        cnt = 0;
        res = 0;
        memset(vis,0,sizeof vis);
        _dfs(0);
        cout << total << endl;
    }
    return 0;
}