#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int _beg,_end;
const int maxn = 505;
int v[maxn],w[maxn];
int dp[10010];

int main()
{
    int T;
    cin >> T;
    while (T--) {

        scanf("%d %d",&_beg,&_end);
        int bottle = _end - _beg;
        int n;
        scanf("%d",&n);

        for (int i = 1; i <= n; i++){
            scanf("%d %d",&v[i],&w[i]);
        }
        
        memset(dp,0x3f3f3f3f,sizeof dp);
        dp[0] = 0;

        for (int i = 1; i <= n;i ++) {
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