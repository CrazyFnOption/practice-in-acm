#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n;
struct Box {
    int l,w,h;
    Box(){};
    Box(int a,int b,int c) :l(a),w(b),h(c){};
    bool operator < (const Box &b) const {
        if (l == b.l) return w < b.w;
        return l < b.l;
    }
};
vector<Box> v;
int tmp[3];
int dp[30000];

int main()
{
    int Case = 1;
    while (cin >> n && n) {
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> tmp[0] >> tmp[1] >> tmp[2];
            sort(tmp,tmp + 3);
            v.push_back(Box(tmp[2], tmp[1], tmp[0]));
            v.push_back(Box(tmp[2], tmp[0], tmp[1]));
            v.push_back(Box(tmp[1], tmp[0], tmp[2]));
        }

        sort(v.begin(),v.end());
        dp[0] = v[0].h;
        int ans = dp[0];

        //再次写了一遍之后发现 为什么不能直接倒着迭代，
        //原因就在于其是从底部一点一点往上面加上去。状态方程就是一点一点往上面加上去的。
        for (int i = 1;i < v.size(); i++) {
            dp[i] = v[i].h;
            for (int j = 0; j < i; j++) {
                if (v[j].l < v[i].l && v[j].w < v[i].w) {
                    dp[i] = max(dp[i],dp[j] + v[i].h);
                }
            }
            ans = max(dp[i], ans);
        }
        cout << "Case " << Case++ << ": maximum height = " << ans << endl;
    }
    return 0;
}