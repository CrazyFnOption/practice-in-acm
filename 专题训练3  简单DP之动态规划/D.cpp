#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 1005;
int dp[maxn];
int num[maxn];

//这道题值得庆祝一下 第一次没有看题解就把这道题给写出来了
//总结一下这类的线性DP。
//这里dp数组保存的是每一个点为止这个位置上的递增子序列之和
//然后这个地方的每一个确定的值再与之前的去比较，最后加上相应的值即可。

int main()
{   
    int T;
    while (cin >> T && T) {
        for (int i = 1 ;i <= T; i++) {
            cin >> num[i];
        }
        memset(dp,0,sizeof dp);
        dp[1] = num[1];
        for (int i = 2; i <= T; i++) {
            dp[i] = num[i];
            for (int j = i - 1; j >= 1; j--) {
                if (num[i] > num[j]) {
                    dp[i] = max(dp[i],dp[j] + num[i]);
                }
            }
        }
        int Max = 0;
        for (int i = 1; i <= T; i++) {
            Max = max(Max,dp[i]);   
        }
        cout << Max << endl;
    }
    return 0;
}