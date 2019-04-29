/*
	这道题也是一道模板题目,
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1005;
int dp[maxn];
int num[maxn];
int N;

int main()
{
    while (cin >> N) {
        for (int i = 1; i <= N ; i++) {
            cin >> num[i];
        }
        dp[1] = 1;
        for (int i = 1; i <= N; i++) {
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if (num[i] >= num[j] && dp[i] < dp[j] + 1) 
                    dp[i] = dp[j] + 1;
            }
        }
        cout << dp[N] << endl;
    }
    return 0;
}