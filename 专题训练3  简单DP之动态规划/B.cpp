#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Box {
    int l,w,h;
    Box(int a,int b,int c) : l(a),w(b),h(c) {}
    bool operator < (Box b) const {
        if (l == b.l) return w < b.w;
        return l < b.l;
    }
};

int dp[30000];

int main()
{
    int n;
    int tmp[3];
    int Case = 1;
    while (cin >> n && n) {
        vector<Box>boxs;
        for (int i = 0; i < n; i++) {
            cin >> tmp[0] >> tmp[1] >> tmp[2];
            sort(tmp,tmp + 3);
            boxs.push_back(Box(tmp[2],tmp[1],tmp[0]));
            boxs.push_back(Box(tmp[2],tmp[0],tmp[1]));
            boxs.push_back(Box(tmp[1],tmp[0],tmp[2]));
        }
        //这道题目的排序的从大到小的问题需要注意
        //这里需要补充的C++知识就是sort默认是按照重载的'<'来进行排序。
        sort(boxs.begin(),boxs.end());
            
        dp[0] = boxs[0].h;

        int ans = dp[0];

        for (int i = 1; i < boxs.size(); i++) {
            //这里是将当前盒子往下面放
            dp[i] = boxs[i].h;
            for (int j = 0; j < i; j++) {
                //上面提到，既然是往下面放置的话，那么所有在当前块下面的一定都是小于当前块，这样才符合题目的要求
                if (boxs[j].w < boxs[i].w && boxs[j].l < boxs[i].l) {
                    dp[i] = max(dp[i],dp[j] + boxs[i].h);
                }
            }
            ans = max(dp[i],ans);
        }
        cout << "Case "<< Case++ <<": maximum height = " << ans << endl;
    }

    return 0;
}