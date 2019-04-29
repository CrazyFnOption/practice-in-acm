#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int dp[60000][11];
int three[11];
int digit[60000][11];
int tu[15][15];
int n,m;

const int INF = 0x3f3f3f3f;

void init() {
    three[0] = 1;
    for (int i = 1; i < 11; i++) {
        three[i] = three[i - 1] * 3;
    }
    for (int i = 0; i < three[10]; i++) {
        int tem = i;
        for (int j = 0; j < 10; j++) {
            //这个步骤就是常常用来求解每一位的位数的 类似于二进制的求解方法
            digit[i][j] = tem % 3;
            tem /= 3;
        }
    }
}

int main()
{
    init();
    while (~scanf("%d%d",&n,&m)) {
        memset(dp,INF,sizeof dp);
        memset(tu,INF,sizeof tu);

        while (m--) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            tu[a - 1][b - 1] = tu[b - 1][a - 1] = min(c,tu[a - 1][b - 1]);
        }

        for (int i = 0; i < n; i++)
            dp[three[i]][i] = 0;
        int ans = INF;

        //下面动态规划开始了
        for (int j = 0; j < three[n]; j++) {
            bool flag = 1;
            for (int i = 0; i < n; i++) {
                if (digit[j][i] == 0) flag = 0;
                if (digit[j][i] != INF) {
                    for (int k = 0; k < n; k++) {
                        if (tu[i][k] != INF && digit[j][k] != 2) {
                            dp[j + three[k]][k] = min(dp[j][i] + tu[i][k],dp[j + three[k]][k]);
                        }
                    }
                }
            }
            if (flag) {
                for (int i = 0; i < n; i++) {
                    ans = min(ans,dp[j][i]);
                }
            }
        }
        if (ans >= INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}