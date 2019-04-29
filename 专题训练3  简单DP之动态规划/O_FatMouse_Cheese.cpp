/*
	第一次做这种将dfs递归与动态规划联系在一起的题目，这里感觉特别的新颖
    状态转移方程就像下面所说的。

    这道题在刚刚开始看的时候完全没有想到是要运用到dfs，知道看到了题解，由于这道题属于一道意料之外的题目。
    关于这道题 dp的选择，dp[i][j] 代表的就是从某个点出发能吃到的最多的食物。
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int n,k;
const int maxn = 1005;
int num[maxn][maxn];
int dp [maxn][maxn];
int Max;
const int _move[4][2] = {1,0,-1,0,0,1,0,-1};

//这是一个进行判断的函数，这个函数存在的意义就是判断有没有出界。
bool check (int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n)
        return false;
    return true;
}

void dfs(int a,int b) {
    int dx,dy,_max = 0;
    //这里摆明的就是一个记忆化搜索的地方，已经遍历过的值就不需要再走了
    if (dp[a][b]) {
        return;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 4; j++) {
            dx = a + _move[j][0] * i;
            dy = b + _move[j][1] * i;
            if (check(dx,dy) && num[dx][dy] > num[a][b]) {
                dfs(dx,dy);
                _max = max(_max,dp[dx][dy]);
            }
        }
    }
    //这里必须放到后面的原因就在于 这里的比较是必须经过多次比较而言 ，就像是一个回溯一样
    //从最初的起点，加上前面由于递归得到的运行最大步数的值
    //就得到了DP的这个数组的意义。
    dp[a][b] = _max + num[a][b];
    Max = max(Max,dp[a][b]);
    return ;
}

int main()
{
    while (cin >> n >> k) {
        if (n == -1 && k == -1) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> num[i][j];
            }
        }
        Max = 0;
        memset(dp,0,sizeof dp);
        dfs(1,1);
        cout << Max << endl;  
    }
    return 0;
}