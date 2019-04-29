/*
	这个地方就直接就是答案的思路了，由一种倒叙的方法往前面推，将对角线存储的数，
    就是当前能存储到的最大的矩阵。
    状态转移方程就是 dp[i][j] 由 dp[i - k][j]与 dp[i][j - k] 是否相等然后再来存储
    不过这里有一个技巧就是 每一个仅仅只是存储这个数组能够承受的最大值、

    自己想的办法没有考虑到状态的迁移，也就是没有考虑到状态与状态之间的联系，这里就展现出来了。
    将每一个值存储到dp[i - 1][j + 1] 上，然后再一次对其进行验证。
    
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n;

const int maxn = 1005;
char ch [maxn][maxn];
int dp  [maxn][maxn];

int main()
{
    while (cin >> n && n) {
        getchar();
        for (int i = 1; i <= n; i++) {
            for (int j = 1 ; j <= n; j++) {
                cin >> ch[i][j];
                dp[i][j] = 1;
            }
            getchar();
        }
        int Max = 1;
        for(int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                if (i == 1 || j == n) continue;
                int tmp = dp[i - 1][j + 1];
                for (int k = 1; k <= tmp; k++) {
                    if (ch[i - k][j] == ch[i][j + k]) dp[i][j]++;
                    else break;
                }
                Max = max (Max,dp[i][j]);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}