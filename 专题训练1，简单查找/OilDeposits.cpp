#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int m,n;

const int maxn = 105;
char map [maxn][maxn];
int cnt;

void dfs(int i,int j) {
    if (i < 0 && i >= m) return;
    if (j < 0 && j >= n) return;
    if (map[i][j] == '@') {
        map[i][j] = '.';
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
        dfs(i,j+1);
        dfs(i-1,j-1);
        dfs(i-1,j+1);
        dfs(i+1,j-1);
        dfs(i+1,j+1);
    }
}
int main() 
{
    while (cin >> m && m != 0 && cin >> n) 
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin >> map[i][j];
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n ; j++) {
                if (map[i][j] == '@'){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
}