#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

#define mod 100000000

int m,n,tot,num;
int state[1000];
int dp[20][1000];
int res[20];

bool ok(int x) {
    if (x & x << 1) return false;
    return true;
}

bool fit(int i,int k) {
    if (i & res[k]) return false;
    return true;
}

void init() {
    memset(dp,0,sizeof dp);
    tot = 0;
    int total = 1 << n;
    for (int i = 0; i < total;i++) {
        if (ok(i)) state[++tot] = i;
    }
}

int main()
{
    while(~scanf("%d %d",&m,&n)) {
        init();
        for (int i = 1; i <= m; i++) {
            res[i] = 0;
            for (int j = 1; j <= n; j++) {
                scanf("%d",&num);
                if (num == 0) res[i] += 1 << (n - j);
            }
        }
        for (int i = 1; i <= tot; i++) {
            if (fit(state[i],1)) dp[1][i] = 1;
        }
        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= tot; j++) {
                if (!fit(state[j],i)) continue;
                for (int k = 1; k <= tot; k++) {
                    if (!fit(state[k],i - 1)) continue;
                    if (state[j] & state[k]) continue;
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= tot ;i ++) {
            ans = (ans + dp[m][i]) % mod;
        }
        printf("%d\n",ans);
    }


    return 0;
}