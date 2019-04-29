/*
	这道题目神奇的地方 是两个背包的问题 的总和，其实也算作是一个简单的题目，但是 这道题唯一复杂的地方就在于对于背包问题的理解
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int maxn = 30005;
int dp[maxn],back[maxn];
int value[105],number[105];

int bag;
int n,k;

void zeroonepack(int weight,int value){
    for (int j = bag ; j >= weight; j--) {
        dp[j] = min(dp[j],dp[j - weight] + value);
    }
}

void completepack(int weight,int value) {
    for (int j = weight; j <= bag; j++) {
        dp[j] = min(dp[j],dp[j - weight] + value);
    }
}

void mutipack(int weight,int value,int number) {
    if (number * weight >= bag) {
        completepack(weight,value);
        return;
    }

    int k = 1;
    while (k < number) {
        zeroonepack(k * weight,k * value);
        number = number - k;
        k *= 2;
    }
    zeroonepack(number * weight , number * value);
}

int main()
{
    while (cin >> n >> k) {

        for (int i = 1; i <= n; i++) {
            cin >> value[i] ;
        }

        for (int i = 1; i <= n; i++) {
            cin >> number[i];
        }

        memset(dp,0x3f3f3f3f,sizeof dp);
        memset(back,0x3f3f3f3f,sizeof back);
        dp[0] = 0;
        back[0] = 0;
        bag = k + 20000;

        for (int i = 1; i <= n; i++) {
            for (int j = value[i]; j <= bag; j++) {
                back[j] = min(back[j],back[j - value[i]] + 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            mutipack(value[i],1,number[i]);
        }

        int ans = 0x3f3f3f3f;
        for (int i = k; i <= bag; i++) {
            ans = min(ans,back[i - k] + dp[i]);
        }

        if (ans == 0x3f3f3f3f) cout << -1 << endl;
        else cout << ans << endl;
    }


    return 0;
}