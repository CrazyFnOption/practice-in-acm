#include<iostream>
#include<string>
#include<cstring>

const int maxn = 1005;
using namespace std;

long long dp[maxn] ;

long long fun(long n) {
    if (dp[n] != 0) return dp[n];
    else return dp[n] = fun(n - 1) + fun(n - 2);
}

int main() 
{
    int T;
    long x;
    cin >> T;
    memset(dp,0,sizeof dp);
    dp[1] = 1;
    dp[2] = 1;
    while (T--)
    {
        cin >> x;
        cout << fun(x) << endl;
    }
}