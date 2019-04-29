#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int maxn = 1005;
int n;
int dp[maxn];
int num[maxn];


int main()
{
    while (cin >> n && n != 0) {
        int Max = 0;
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            dp[i] = num[i];
        }

        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (num[i] > num[j])
                    dp[i] = max(dp[i],dp[j] + num[i]);
                    
            }
        }

        for (int i = 1; i <= n ;i++) {
            Max = max(Max,dp[i]);
        }
        cout << Max << endl;
    }
}
