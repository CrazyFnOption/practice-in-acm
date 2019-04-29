/*
	这道题目就是典型的区间DP的题目了，对一个区间里面的值进行动态规划的求解，就像下面的状态转移方程
    dp[i][j] = max(dp[i + 1][j] + num[i] *(n + i - j),dp[i][j - 1] + num[j] * (n + i - j));

    这道题唯一特别难想到的是，这道题目是一道逆序求解的问题，意思就是从后面的状态往前面推，这当时的我就完全没有想到了。
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int n;
const int maxn = 2005;
int dp[maxn][maxn];
int num[maxn];

int main()
{
    while (~scanf("%d",&n)) {
        memset(dp,0,sizeof dp);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&num[i]);
            dp[i][i] = num[i] ;
        }
        for (int i = n ; i >= 1; i--) {
            for (int j = i ; j <= n; j++) {
                //这里乘以 n + i - j 其实一开始的变形就是 n - (j - i + 1) + 1
                dp[i][j] = max(dp[i + 1][j] + num[i] * (n + i - j),dp[i][j - 1] + num[j] * (n + i - j));
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}