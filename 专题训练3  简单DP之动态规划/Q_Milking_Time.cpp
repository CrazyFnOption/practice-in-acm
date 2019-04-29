/*
	其实这道题当时自己没有想出来挺意外的，属于一个简单dp 两个循环 一个正向 ，一个 另一个检索循环来判断到达dp[i]的最佳状态
    这道题属于一道简单的dp题目，与前面几种dp的题目类似。
    不过下次 需要多想一想再开始看答案的题目。

    另外需要注意的是 对于像这类的题目 不像之前碰到的状压dp 他可能会在同一个状态中有不同种情况 
    所以 下面的第二个循环开始就有不同的方向。所以对于这道题而言 就无所谓下面的顺序了。
    
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1005;
int N,M,R;

struct FJ{
    int _beg;
    int _end;
    int _eff;
    bool operator < (const FJ & f) const {
        if (_beg == f._beg) {
            if (_end == f._end) return _eff > f._eff;
            return _end < f._end;
        }
        return _beg < f._beg;
    }
}fj[maxn];
int dp[maxn];

int main()
{
    while (cin >> N >> M >> R) {
        for (int i = 1 ;i <= M; i++) {
            cin >> fj[i]._beg >> fj[i]._end >> fj[i]._eff;
            fj[i]._end += R;
        }
        stable_sort(fj+1,fj+1+M);
        dp[1] = fj[1]._eff;
        int Max = 0;
        for (int i = 2; i <= M; i++) {
            dp[i] = fj[i]._eff;
            for (int j = 1; j < i; j++) {
                if (fj[j]._end <= fj[i]._beg) {
                    dp[i] = max(dp[j] + fj[i]._eff,dp[i]);
                }
                
            }
            Max = max (Max,dp[i]);
        }
        cout << Max << endl;
    }

    return 0;
}