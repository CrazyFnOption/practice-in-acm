#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n,m;

int dp[13000];
int w[3500],v[3500];

int main()
{
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        }
        memset(dp,0,sizeof dp);

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= w[i]; j--) {
                dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[m] << endl;
    }

    return 0;
}