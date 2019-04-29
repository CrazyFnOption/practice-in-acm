/*
	这道题属于一道三维DP的题目，而我在这里将这道题先放到后面开始看背包的时候再来开始看。
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

const int maxn = 223;
struct Person {
    int id;
    int kong;
    int bian;
}person[maxn];

int m,n;
int dp[maxn][maxn];

int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> person[i].kong >> person[i].bian;
        person[i].id = i;
    }



    return 0;
}