#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

#define inf 0x3f3f3f3f

const int maxn = 1 << 15;

int dp[maxn], _time[maxn], pre[maxn];
int deadline[16], finish[16];
string name[16];

//正常的输出顺序与递归的输出顺序永远是反着来的。

void output(int x) {
    if (!x) return ;
    output(x -(1 << pre[x]));
    cout << name[pre[x]] << endl;
}

int main()
{
    int T,n;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(_time,0,sizeof _time);
        for (int i = 0; i < n ; i++) {
            cin >> name[i] >> deadline[i] >> finish[i];
        }

        int bit = 1 << n;
        for (int i = 1; i < bit ; i ++) {
            dp[i] = inf;
            for (int j = n - 1; j >= 0; j--) {
                int tmp = 1 << j;
                if (!(tmp & i)) continue;
                int score = _time[i - tmp] + finish[j] - deadline[j];
                if (score < 0) score = 0;
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