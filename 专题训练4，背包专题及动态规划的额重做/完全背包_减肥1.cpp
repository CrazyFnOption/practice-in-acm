/*
	这道题使用二维数组就一直就会超时 具体的我也不太清楚，但是 没有办法 只能使用一维滚动数组，进行了相应的空间优化 不过这里需要补充几个知识点

    第一 关于二维数组的完全背包状态转移方程 dp[i][j] = max (dp[i - 1][j],dp[i - 1][j - k * c[i]] + k * v[i]);
    由上面这个式子就可以得出，状态转移方程  于是 一种空间优化的写法 是直接写成 max(dp[i - 1][j]，dp[i][j - w[i]] + v[i])

    第二 如果换成滚动数组的话 记住 第二个循环的两个顺序，如果是倒叙的话 则就是要保证每一个物品只会取一次，但是如果是正序的话，那么就不需要保证上面所说的顺序了。

    而这里官方的解释 就在这里 ：
    让 v 递减是为了保证第i次循环中的状态F[i;v]是由状态F[i-1;v-Ci]递推而来。
    换句话说，这正是为了保证每件物品只选一次，保证在考虑“选入第 i 件物品”这件策
    略时，依据的是一个绝无已经选入第 i 件物品的子结果F[i-1;v-Ci]。而现在完全背
    包的特点恰是每种物品可选无限件，所以在考虑“加选一件第 i 种物品”这种策略时，
    却正需要一个可能已选入第 i 种物品的子结果F[i;v-Ci]，所以就可以并且必须采用v
    递增的顺序循环。这就是这个简单的程序为何成立的道理。

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include<cstdio>
using namespace std;

int n, a, b, m;
const int maxn = 110;
int happiness[maxn], kaluli[maxn];
int dp[110000];

int main()
{
    while (~scanf("%d",&n))
    {

        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d",&happiness[i],&kaluli[i]);
        }
        scanf("%d",&m);
        memset(dp,0,sizeof dp);
        for (int i = 1; i <= n; i++) {
            for (int j = kaluli[i]; j <= m; j++) {
                dp[j] = max(dp[j],dp[j - kaluli[i]] + happiness[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
