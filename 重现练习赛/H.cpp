#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n,k;
const int maxn = 1005;
int dp[maxn + 1],v[maxn + 1],w[maxn + 1];


int main()
{
    for (int i = 1; i <= maxn;i++) {
        w[i] = i;
    }
    while(cin >> n >> k) {
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = w[i]; j <= n; j++) {
                dp[j] = dp[j] + dp[j - i];
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}