#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int _beg,_end;
const int maxn = 510;
int n;
int v[maxn],w[maxn];
int dp[10004];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> _beg >> _end;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i] >> w[i];
        }
        memset(dp,0x3f3f3f3f,sizeof dp);
        int bottle = _end - _beg;
        dp[0] = 0;

        //不要忘记上面的这个步骤，其实在上面的来说这个步骤常见的一点就在于这里了关于求最大背包的值 与 最小背包的值区别就在这里
        //但是请不要忘记对于第一个状态的标明。

        for (int i = 1; i <= n; i++) {
            for (int j = w[i]; j <= bottle; j++) {
                dp[j] = min(dp[j],dp[j - w[i]] + v[i]);
            }
        }
        if (dp[bottle] != 0x3f3f3f3f)
            cout << "The minimum amount of money in the piggy-bank is " << dp[bottle] << "." << endl;
        else
            cout << "This is impossible." << endl;
    }
    return 0;
}