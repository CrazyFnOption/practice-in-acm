/*
	一段简单的模板题目，不过需要弄清楚的 一维数组与二维数组在这里相应的区别，往往这里会产生很大的区别，
    比如第二个循环的开始条件，因为这里是由子问题的堆积，然后一点一点向上升最终得到的问题，所以这李最好控制背包的放与不放的问题、
    就比如我在这道题目的第二个问题中出现的错误，就是将j=0这个条件直接掠过去了，其实这里是不对的。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1010;
long long weight[maxn],value[maxn],dp[maxn][maxn];
long v,w;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        cin >> w >> v;
        value[0] = 0;
        weight[0] = 0;

        for (int i = 1; i <= w; i++) {
            cin >> value[i];
        }

        for (int i = 1; i <= w; i++) {
            cin >> weight[i];
        }

        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= w; i++) {
            for (int j = 0; j <= v; j++) {
                if (j >= weight[i]) {
                    dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }
        cout << dp[w][v] << endl;
    }
    return 0;
}