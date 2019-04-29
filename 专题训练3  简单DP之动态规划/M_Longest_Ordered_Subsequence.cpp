/*
	这道题也是一道模板题目,不过自己第一次没有考虑到的是，
    前面需要弄清楚的是自己并没有在下面一次比较的时候做一个相应的限制，这样就不会出现
    只要比前面的小的就记下来，反而造成了其他许多多余的错误。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1005;
int dp[maxn];
int num[maxn];
int N;

int main()
{
    while (cin >> N) {
        for (int i = 1; i <= N ; i++) {
            cin >> num[i];
        }
        dp[1] = 1;
        int Max = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if (num[i] > num[j] && dp[i] < dp[j] + 1) 
                    dp[i] = dp[j] + 1;
            }
            Max = max(Max,dp[i]);
        }
        cout << Max << endl;
    }
    return 0;
}