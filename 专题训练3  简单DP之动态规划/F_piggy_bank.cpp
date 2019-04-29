/*
	一道典型的背包题目，并且这道题目的核心并不在这个地方，
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int a,b,W,n;
int v[505],w[505];
int dp[505][10060];

#define inf 0x3f3f3f3f

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        W = b - a;
        cin >> n;
        for (int i = 0; i < n ; i++) {
            cin >> v[i] >> w[i];
        }
        memset(dp,0x3f3f3f3f,sizeof dp); 
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
            for (int j = 0; j <= W; j++) 
            {
                if (j >= w[i]) {
                    dp[i + 1][j] = min(dp[i][j],dp[i + 1][j - w[i]] + v[i]);
                }
                else
                    dp[i + 1][j] = dp[i][j];
            }
        }
        if (dp[n][W] >= 0x3f3f3f3f)
            cout << "This is impossible."<< endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[n][W] << "." << endl;
    }

    return 0;
}

