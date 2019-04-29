#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100005;
int n;
int dp[maxn][11];
int date[maxn][11];
int _time, pie;

int main()
{
    while (scanf("%d", &n) && n != 0)
    {
        memset(date, 0, sizeof date);
        memset(dp, 0, sizeof dp);
        int maxTime = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &pie, &_time);
            date[_time][pie]++;
            maxTime = max(maxTime, _time);
        }
        //第一秒的运行时间，里面所有的运行情况
        dp[1][4] = date[1][4];
        dp[1][5] = date[1][5];
        dp[1][6] = date[1][6];

        //这里其实是由第二次运转的时间来看，因为第一秒的时间我已经全部标记下来了。
        for (int i = 2; i <= maxTime; i++) {
            for (int j = 0; j < 11; j++) {
                dp[i][j] = dp[i - 1][j];
                //不过需要注意的是 这些全部都是前几秒的动作，上一秒更新的状态，到下一秒后执行的状态
                //下面这个地方就是很奇幻的地方了，一共三个状态，取出来还是不取出来，就是这三种状态
                //左边一个位置取，还是右边一个位置取，还是原本的位置去出来。
                if (j > 0) 
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                if (j < 10)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                dp[i][j] += date[i][j];
            }
        }
        int Max = 0;
        for (int i = 0; i < 11; i++)
        {
            Max = max(Max, dp[maxTime][i]);
        }
        cout << Max << endl;
    }
    return 0;
}