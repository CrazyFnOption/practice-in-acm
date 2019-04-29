#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

#define inf 0x3f3f3f3f
const int maxn = 1 << 15;

int dp[maxn],_time[maxn],pre[maxn];
int deadline[16],finish[16];
string name[16];

void output (int x) {
    if (!x) return;
    output(x - (1 << pre[x]));
    cout << name[pre[x]] << endl;
}


int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        memset(_time,0,sizeof _time);
        for (int i = 0 ; i < n; i ++) {
            cin >> name[i] >> deadline[i] >> finish[i];
        }
        int bit = 1 << n;
        //这里之所以从1开始的原因就是其排列的情况实际上是2的n次方减去1
        for (int i = 1;i < bit;i++) {
            dp[i] = inf;
            //这里需要表示的是 下面有一个判断条件 dp[i] >= dp[i - tmp] + score
            //当其出现等于号的时候，这里就可以从0开始遍历，但是没有等于号的时候只能反过来遍历。
            //这里就是状压DP神奇的地方了，像这样排列顺序有很多，但是排列顺序的时候 往往最小的取到之后会有很多相同模式的造成影响
            for (int j = n - 1;j >= 0;j --) {
                int tmp = 1 << j;
                if (!(tmp & i)) continue;
                int score = _time[i - tmp] + finish[j] - deadline[j];
                if (score < 0) score = 0;
                //就像这个地方，当满足以下条件之后，后面仍然会出现相应的操作，往往从大到小的就不会重复选择后面的操作。
                if (dp[i] > dp[i - tmp] + score) {
                    dp[i] = dp[i - tmp] + score;
                    _time[i] = _time[i - tmp] + finish[j];
                    pre[i] = j;
                }
            }
        }
        cout << dp[bit - 1] << endl;
        output(bit - 1);
    }
    return 0;
}