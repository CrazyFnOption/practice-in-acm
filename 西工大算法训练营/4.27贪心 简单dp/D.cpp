/*
	这道题目可能受前面的影响，一上来就直接开始了欢快的排序，然后将上面的开始时间与结束时间进行一个欢快的排序
    但是实际上对于每一个位置进行贪心就可以去解决 找到的最优解，从左向右遍历，如果遇到了走不到的点，直接去掉对后面影响最大的就可以了

    实际上这道题目 需要注意的就是后面当你拆除一个墙的时候 需要办到的是将其拆除后的结果也考虑其中。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int beg_x,beg_y;
    int end_x,end_y;
}node[105];

int col[105];

int n,k;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int Max_right = -1;
        for (int i = 1; i <= n ;i++) {
            cin >> node[i].beg_x >> node[i].beg_y >> node[i].end_x >> node[i].end_y;
            if (node[i].beg_x > node[i].end_x)
                swap(node[i].beg_x, node[i].end_x);
            Max_right = max(Max_right,node[i].end_x);
        }
        memset(col,0,sizeof col);
        for (int j = 1; j <= n; j++) {
            for (int l = node[j].beg_x; l <= node[j].end_x; l++) {
                col[l]++;
            }
        }

        int tmp,ans = 0;
        int res,res_id;

        for (int i = 0; i <= Max_right; i++) {
            if (col[i] <= k) continue;
            tmp = col[i] - k;
            
            while (tmp --) {
                res = -1;
                for (int j = 1; j <= n; j++) {
                    if (i >= node[j].beg_x && i <= node[j].end_x && res < node[j].end_x) {
                        res = node[j].end_x;
                        res_id = j;
                    }
                }

                for (int i = node[res_id].beg_x; i <= node[res_id].end_x; i++) {
                    col[i]--;
                }

                node[res_id].end_x = -1;
                ans++;

            }
        }
    cout << ans << endl;
    }

    return 0;
}