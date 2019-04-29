/*
    其实这道题目是一道简单的dp，但是很多时候并不是题目的难，也不是dp的状态转移方程难以想到，有的时候仅仅可能就是
    这道题目没有完全弄清楚，

    而这道题真正的意思就是使其变成一个单调性质的函数，
    首先得到数的序列之后将其变成一个单调性质的函数，即 直接用sort使其变成相应的排序
    但是这道题 我先开始的想法就是 由于是变成一个单调性质的序列，所以就意味着每个人都有对应的位置，所以直接sort完减去相应的最终位置就可以了
    
    最后才发现，原来是我想的太天真了，
    他这里是 修改任意数字的值，使其变成非严格的递增序列，或者是非严格递减序列。
    
    其实这道题 有点像在搜索专题里面做到的 向下翻转格子的题目，从最上面的状态开始找寻状态，直到最后比较最后一行来判断是否 可以得到最终结果。
    具体见代码中的标注。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long N;
const long maxn = 2005;
long dp[maxn][maxn];
long num[maxn];
long dt[maxn];

long solve() {
    
    for (long k = 1; k <= N; k++) {
        dp[1][k] = abs(num[1] - dt[k]);
    }

    for (long i = 2; i <= N; i++) {
        long tmp = dp[i - 1][1];
        for (long j = 1; j <= N; j++) {
            //最重要的就是这一块，这里是将每一行的花费最小的直接存储到了tmp里面，
            //然后将其加到了 dp[i][j]上面即可以得到一个横向的最小值，然后再最终状态去比较一个纵向的最小值。
            tmp = min(tmp,dp[i - 1][j]);
            dp[i][j] = tmp + abs(num[i] - dt[j]);
            //与之前所说的搜索专题那道题不一样的是，
            //这是直接由上面的情况来按住下面的情况的，不存在什么最小与最大。
            //就是取第i-1的数字 在更改后的序列里面的第i个数字的排序的最小代价，其实每一个都遇到过，最后轻松的到答案。
        }
    }

    //这里在解释一下 状态转移方程，意思就是在第i-1个数 决定第i个数的同时，现将第i-1个数字的最小情况存储起来

    long tmp = dp[N][1];
    for (long i = 1; i <= N; i++) {
        tmp = min(tmp,dp[N][i]);
    }
    return tmp;
}

bool cmp (long a,long b) {
    return a > b;
}

int main()
{
    while (cin >> N) {
        memset(dp,0,sizeof dp);
        for (long i = 1; i <= N; i++) {
            cin >> num[i];
            dt[i] = num[i];
        }
        sort(dt + 1, dt + 1 + N);
        long Min_1 = solve();
        sort(dt + 1, dt + 1 + N, cmp);
        long Min_2 = solve();
        cout << min(Min_1,Min_2) << endl;
    }
    
    return 0;
}



   