#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    int T;
    while(~scanf("%d",&T)) {
        int dp[T+5];
        int data[T+5];
        data[0] = 0;
        int num = 0;
        for (int i = 1; i <= T; i++) {
            scanf("%d",data + i);
            dp[i] = 1;
        }
        for (int i = 2; i <= T; i++) {
            for (int j = i - 1; j >= 1 ;j--) {
                if (data[i] > data[j]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
                num = max(num,dp[i]);
            }
        }
        printf("%d\n",num);
    }


    return 0;
}