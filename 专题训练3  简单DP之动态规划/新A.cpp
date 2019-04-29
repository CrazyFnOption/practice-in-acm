#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

//需要去弄清楚滚动数组


using namespace std;

const int maxn = 1000005;

int dp[maxn];
int num[maxn];
//这里出现的第二个数组很奇怪，我先开始也是一直都没有想通，直到后来我弄懂后面的递推方程式之后我才有所感悟
//这里就相当于将每一段隔离开来之后，算出一个隔离开来的最大值。
int pre[maxn];//对应递推式的第二项
int m,n;


int main()
{
    while (~scanf("%d %d",&m,&n)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d",num + i);
        }
        memset(dp,0,sizeof dp);
        memset(pre,0,sizeof pre);

        int Max;
        //此处是保证前坠这里一定的取值是为0
        dp[0] = pre[0] = 0;
        //注意这里之所以存在两个循环原因是主要是求出有i段然后利用滚动数组来进行求解
        for (int i = 1; i <= m ;i++) {
            Max = -999999999;
            for (int j = i; j <= n; j++) {
                //这里有意思的一点就是 需要判断的是 这里是独自成为一段
                //还是跟之前的一起成为一段。
                //最终的意思就是pre这个数组表示上一次的最大值i-1个同时的最大的dp
                dp[j] = max(dp[j - 1],pre[j - 1]);
                dp[j] += num[j];
                //pre表示前一个数的最大值
                pre[j - 1] = Max;
                Max = max(dp[j],Max);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}