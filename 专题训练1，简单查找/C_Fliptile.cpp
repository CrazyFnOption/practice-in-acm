#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 17;

int cpy[maxn][maxn];
int map[maxn][maxn];
int res[maxn][maxn];

int n,m;
int Min;

bool judge() {
    for (int i = 1; i <= m; i ++) {
        int tmp = cpy[n][i] + cpy[n][i - 1] + cpy[n][i + 1] + cpy[n - 1][i];
        if ((map[n][i] + tmp) & 1) return false;
    }
    return true;
}

void dfs(int a,int num) {
    
    if (num > Min) return;

    if (a > n) {
        if (judge() && Min > num) {
            Min = num;
            memcpy(res,cpy,sizeof (cpy));
            return ;
        }
        return;
    }

    int _time = 0;

    for (int i = 1 ; i <= m; i ++) {
        int tmp = map[a - 1][i] + cpy[a - 1][i] + cpy[a - 2][i] + cpy[a - 1][i - 1] + cpy[a - 1][i + 1];

        if (tmp & 1) {
            cpy[a][i] = 1;
            _time ++;
        }

        else cpy[a][i] = 0;
    }

    dfs(a + 1, num + _time);
}

void solve(int a,int num) {
    if (a > m) {
        dfs(2,num);
        return ;
    }
    cpy[1][a] = 0;
    solve(a + 1,num);
    cpy[1][a] = 1;
    solve(a + 1,num + 1);
}

void get()
{
    while( cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j];
            }
        }
        Min = 0x3f3f3f3f;
        memset(cpy,0,sizeof(cpy));
        solve(1,0);
        if (Min == 0x3f3f3f3f)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}


int main()
{
    get();
    return 0;
}