/*
	一道多重背包的裸题目
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int h,a,c;
    bool operator < (const Node &n) const {
        return a < n.a;
    }
}node[450];

int dp[40050];
int main()
{
    int K;
    while (cin >> K) {
        for (int i = 1; i <= K; i++) {
            cin >> node[i].h >> node[i].a >> node[i].c;
        }
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        sort(node + 1, node + 1 + K);
        for (int i = 1; i <= K ;i ++) {
            for (int j = 1; j <= node[i].c; j++) {
                for (int k = node[i].a; k >= node[i].h; k-- ){
                    dp[k] |= dp[k - node[i].h];
                }
            }
        }
        int cnt = 0;
        for (int i = node[K].a; i >= 0; i--) {
            if (dp[i]) {
                cnt = i;
                break;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}