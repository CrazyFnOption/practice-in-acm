/*
	这道题神奇的地方就在于 其的重量限制于价值重合在了一起，所以对于这道题而言就是只能重合的去写状态转移方程了
    另外需要注意的是最后输出结果的办法，是将最后一个物品交给剩下的最大的钱去购买，这样能彻底用光最后的钱财
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n,m;
const int maxn = 1010;
int num[maxn],dp[maxn][maxn];

int main()
{
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
        }
        cin >> m;
        sort(num + 1, num + 1 + n);
        if (m < 5) {
            cout << m << endl;
            continue;
        }
        memset(dp,0,sizeof dp);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m - 5; j++) {
                if (j >= num[i]) {
                    dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - num[i]] + num[i]);
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }
        cout << m - dp[n - 1][m - 5] - num[n] << endl;
    }
    return 0;
}