#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 100000 + 5;
struct Node
{
    
    int _beg, _end;
    bool operator<(const Node &n) const
    {
        if (_end == n._end)
            return _beg < n._beg;
        return _end < n._end;
    }
} node[100000 + 5];

int tmp[maxn],res[maxn],beg[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d",&node[i]._beg,&node[i]._end);
            
        }

        stable_sort(node + 1, node + 1 + n);
        tmp[1] = node[1]._end;
        beg[1] = node[1]._beg;
        res[1] = node[1]._end - node[1]._beg;
        int tt = 1;

        for (int i = 2; i <= n; i++)
        {
            bool flag = false;
            for (int j = 1 ; j <= tt; j++) {
                if (tmp[j] < node[i]._beg) {
                    res[j] = node[i]._end - beg[j];
                    tmp[j] = node[i]._end;
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                tt++;
                tmp[tt] = node[i]._end;
                beg[tt] = node[i]._beg;
                res[tt] = node[i]._end - node[i]._beg;
            }
        }
        int sum = 0;
        for (int i = 1; i <= tt; i++) {
            sum += res[i];
        }
        printf("%d %d\n",tt,sum);
    }

    return 0;
}