#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int T;
const int maxn = 32;
int map[maxn][maxn];
int unmap[maxn][maxn];

int dp[4];

int main()
{
    while (cin >> T && T) {
        for (int i = 0;i < T; i++) {
            for (int j = 0;j < T; j++) {
                cin >> map[i][j];
            }
        }
         for (int i = 0;i < T; i++) {
            for (int j = 0;j < T; j++) {
                cin >> unmap[i][j];
            }
        }
        memset(dp,0,sizeof dp);
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < T; j++) {
                if (map[i][j] == unmap[i][j]) dp[0]++;
                if (map[i][j] == unmap[j][T - i - 1])   dp[1]++;
                if (map[i][j] == unmap[T - 1 - i][T - j - 1]) dp[2]++;
                if (map[i][j] == unmap[T - j - 1][i]) dp[3]++;
                
            }
        }

        int Max = 0;
        for (int i = 0; i < 4 ;i++) {
            Max = max (Max,dp[i]);
        }
        cout << Max << endl;
    }
    return 0;
}