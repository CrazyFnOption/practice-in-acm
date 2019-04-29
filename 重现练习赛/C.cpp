#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int M,N;

int map[19][19];
int res[19][19];
int cpy[19][19];
int Min;

bool judge() {
    for (int i = 1; i <= N; i++) {
        int tmp = cpy[M][i] + cpy[M - 1][i] + cpy[M][i - 1] + cpy[M][i + 1];
        if ((tmp + map[M][i] ) & 1)
            return false;
    }
    return true;
}

void dfs(int a,int num) {

    if (num > Min) return ;

    if (a > M) {
        if (judge() && Min > num) {
            Min = num;
            memcpy(res,cpy,sizeof cpy);
            return ;
        }
        return;
    }

    int _time = 0;

    for (int i = 1; i <= N; i++) {
        int tmp = map[a - 1][i] + cpy[a - 1][i] + cpy[a - 2][i] + cpy[a - 1][i - 1] + cpy[a - 1][i + 1];

        if (tmp & 1) {
            cpy[a][i] = 1;
            _time ++;
        }
        else cpy[a][i] = 0;
    }

    dfs(a + 1, num + _time);
}

void solve (int a,int num) {
    if (a > N) {
        dfs(2,num);
        return;
    }
    cpy[1][a] = 0;
    solve(a + 1,num);
    cpy[1][a] = 1;
    solve(a + 1,num + 1);
}

int main()
{
    while (cin >> M >> N) {
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> map[i][j];
            }
        }
        Min = 0x3f3f3f3f;
        memset(cpy,0,sizeof cpy);
        solve(1,0);
        if (Min == 0x3f3f3f3f)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}