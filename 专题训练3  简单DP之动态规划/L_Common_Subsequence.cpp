/*
	这道题目就是一道简单的模板题，属于最长公共子序列的题目，
    关于这道题的状态转移方程就在下面所述的地方。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


string s1,s2,tmp;

int main()
{
    while (cin >> s1 >> s2) {
        if (s1.size() < s2.size()) {
            tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        int dp[s1.size() + 10][s1.size() + 10];
        memset(dp,0,sizeof dp);
        for (int i = 0; i < s2.size(); i++ ) {
            int k = i + 1;
            for (int j = 0; j < s1.size(); j++) {  
                int l = j + 1;
                if (s1[j] == s2[i]) {
                    dp[k][l] = dp[k - 1][l - 1] + 1;
                }
                else dp[k][l] = max(dp[k - 1][l],dp[k][l - 1]);
                
            }
            
        }
        cout << dp[s2.size()][s1.size()] << endl;
    }
    
    return 0;
}