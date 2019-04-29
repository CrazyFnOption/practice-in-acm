#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int maxn = 100005;
int n;
int dp[maxn][11];
int date[maxn][11];
int _time,pie;

int main()
{
    while (scanf("%d",&n) && n != 0) {
        memset(date,0,sizeof date);
        memset(dp,0,sizeof dp);
        int maxTime = 0;
        for (int i = 0;i < n; i++) {
            scanf("%d %d",&pie,&_time);
            date[_time][pie] ++;
            maxTime = max(maxTime,_time);
        }

        //此处则为错误的代码，就是状态的划分出现了问题。
        for (int i = 0; i < 11; i++) {
            for (int j = 1; j <= maxTime; j++) {
                if (j == 1 && (i < 4 && i > 6)) {
                    continue;
                }
                //下面这个地方就是很奇幻的地方了，一共三个状态，取出来还是不取出来，就是这三种状态
                //左边一个位置取，还是右边一个位置取，还是原本的位置去出来。
                dp[j][i] = dp[j - 1][i];
                if (i > 0)
                    dp[j][i] = max(dp[j][i],dp[j - 1][i - 1]);
                if (i < 10)
                    dp[j][i] = max(dp[j][i],dp[j - 1][i + 1]);
                dp[j][i] += date[j][i];

            }
        }
        int Max = 0;
        for (int i = 0; i < 11; i++) {
            Max = max(Max,dp[maxTime][i]);
        }
        cout << Max << endl;

    }
    return 0;
}