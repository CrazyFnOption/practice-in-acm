#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int dp[202][22][802];
int path[201][22][802];
int ans[21];
int d[205];
int ad[205];

int main()
{
    int n,m,P,D;
    int Case = 1;
    while (cin >> n >> m && n && m) {
        memset(dp,-1,sizeof(dp));
        for (int i = 1; i <= n ;i++) {
            cin >> P >> D;
            ad[i] = P + D;
            d[i] = P - D;
        }

        int max_diff = m + 20;
    }
    return 0;
}