/*
	这道题就是被前面的思想所影响，其实这道题不像前面前面几个状态一定会影响到后面的状态，
    仅仅只是一个一维的线性dp，考虑到前面的这些情况，他是另外的两个dp方程组进行放与不放的操作
    所以不会涉及到多个循环反复到前面之前的状态去寻找，只需要在一次遍历的过程中去实现究竟是一次还是两次的操作。

    跟着每一个状态往下面找出每一个位置的局部最优解 最后得到结果。
*/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 2005;
int dp[maxn];
int s[maxn];
int d[maxn];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n ; i++) {
            cin >> s[i];
            dp[i] = s[i];
        }
        d[0] = 0;
        d[1] = 0;
        for (int i = 2; i <= n; i++) {
            cin >> d[i];
        }
        dp[0] = 0;
        dp[1] = s[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + s[i],dp[i - 2] + d[i]);
        }
        int h = dp[n] / 3600 + 8;
        int m = dp[n] / 60 % 60;
        int s = dp[n] % 60;
        printf("%02d:%02d:%02d am\n",h,m,s);
    }
    return 0;
}