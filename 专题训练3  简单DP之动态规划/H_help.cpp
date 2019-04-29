#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int maxn = 1005;

int dp[20005][40005];
multimap <int,pair<int,int> > block;

int main()
{
    int T,N,X,Y,Max,tmp;
    pair <int,int> p;
    cin >> T;
    while (T--) {
        cin >> N >> X >> Y >> Max;
        for (int i = 1; i <= N; i++) {
            cin >> tmp >> p.first >> p.second;
            tmp = Y - tmp;
            block.insert(pair<int,pair<int,int> > (tmp,p));
        }
        dp[Y][X] = 1;
        memset(dp,0,sizeof dp);
        for (int i = 0; i < Y; i++) {
            
            
        }
    }
    return 0;
}