/*
	这道题属于一道贪心的题目，但是被前面几道的疑惑，我一上来就对后面的每一个节点进行一个排序，将结束时间的大小进行一个排序，然后再去模拟这个过程。
    虽然我感觉这个过程我们肯定能过，但是最终导致的结果就是 超时，因为我在模拟的过程中是将每一个多出来的机器存到相应的地方去，但是到最后每一台机器就要遍历好多遍
    所以 就像此题最终的解法，直接将每一台机器的两个时间点都用来排序，随便讲其标记，然后在一个时间轴上跑一次就行了，节省了很多时间。

    贪心策略就是 站在最先开始的时间点，每一段的时间点进行横向扫描 遇到起点时间就加加，遇到结束时间就减减 最后求出在此过程中最大的时间就可以了。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

pair<int,bool> p[200006];

int l[200006],r[200006];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d",&p[i * 2 - 1].first,&p[i * 2].first);
            p[i * 2 - 1].second = true;
            p[i * 2].second = false;
        }

        memset(l,-1,sizeof l);
        memset(r,-1,sizeof r);
        sort(p + 1,p + 1 + 2 * n);
        int ans = 0;
        int num = 0;
        long long sum = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (p[i].second == true) {
                num ++;
                if (l[num] == -1) l[num] = p[i].first;
                ans = max(num,ans);
            }
            else {
                r[num] = p[i].first;
                num--;
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            sum += r[i] - l[i];
        }
        printf("%d %lld\n",ans,sum);
    }
    return 0;
}