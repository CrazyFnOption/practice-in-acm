#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int _time,nums;
const int maxn = 100005;
int dp[maxn][11];
int num[maxn][11];

int main()
{
    while (scanf("%d",&n) && n != 0) {
        memset(dp,0,sizeof dp);
        memset(num,0,sizeof num);
        int Max_time = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d",&nums,&_time);
            num[_time][nums] ++;
            Max_time = max(Max_time,_time);
        }
        //首先弄清楚初始状况
        dp[1][4] = num[1][4];
        dp[1][5] = num[1][5];
        dp[1][6] = num[1][6];
        

        for (int i = 2; i <= Max_time; i++) {
            for (int j = 0; j < 11; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - 1]); 
                }
                if (j < 10) {
                    dp[i][j] = max (dp[i][j],dp[i - 1][j + 1]);
                }
                //以上是上一秒得到的状态 然后统统加上这一得到的状态。
                dp[i][j] += num[i][j];
            }
        }

        int Max = 0;
        for (int i = 0; i < 11; i++)
        {
            Max = max(Max, dp[Max_time][i]);
        }
        cout << Max << endl;
    }

    return 0;
}