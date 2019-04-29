#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1010;
int n;
int date[maxn];
int dp[maxn];

int main()
{
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> date[i];
        }
        int Max = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = date[i];
            for (int j = 1; j < i; j++) {
                if (date[j] < date[i]) {
                    dp[i] = max(dp[i],dp[j] + date[i]);
                }
            }
            Max = max (Max,dp[i]);
        }
        cout << Max << endl;
    }

    return 0;
}