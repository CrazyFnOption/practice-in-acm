/*
	这里其实就是一个错误代码了，与正确代码相差的地方就在于其处理对称矩阵的方式错了，
    少考虑一种情况，以下这种写法仅仅只是考虑从每一个点出发得到的矩阵对称值。
    但是他仅仅只是顺着考虑 就是 只考虑到了矩阵的外围，少考虑了几种情况，于是这种情况不是特别可取的。
    所以 只能像正确答案一样，从一个顶点的左下去逆向翻转去考虑而不是从右上角的正向考虑，这样就不会漏掉多种情况。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n;

const int maxn = 1005;
char ch[maxn][maxn];
int dp[maxn][maxn];

bool check(int i,int j) {
    if (i < 1 || i > n || j < 1 || j > n) return false;
    return true;
}

int main()
{
    while (cin >> n && n)
    {
        getchar();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> ch[i][j];
                dp[i][j] = 1;
            }
            getchar();
        }
        int Max = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1 ;j--) {

                int k = 1;
                while (check(i + k,j - k)) {
                    
                    if (ch[i + k][j] == ch[i][j - k]) {
                        dp[i][j]++;
                        k++;
                    }
                    else break;

                }
                Max = max(Max,dp[i][j]);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}