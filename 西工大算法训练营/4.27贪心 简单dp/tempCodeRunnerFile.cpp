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

int col[15];

int n,k;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int Max_right = 0;
        for (int i = 1; i <= n ;i++) {
            cin >> node[i].beg_x >> node[i].beg_y >> node[i].end_x >> node[i].end_y;
            Max_right = max(Max_right,node[i].end_y);
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
            res = -1;
            while (tmp --) {
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