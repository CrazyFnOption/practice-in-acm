#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
    int T;
    while (cin >> T) {
        int a[T + 5];
        int cnt[T + 5];
        memset(cnt,1,sizeof cnt);
        int i;
        for (i = 1; i <= T;i ++) {
            cin >> a[i];
        }
        a[i] = a[1];
        for (int i = 1; i <= T; i++) {
            if (a[i] < a[i + 1]) {
                cnt[i + 1] ++;
            }
            else if (a[i] > a[i + 1]) {
                cnt[i] ++;
            }
        }

    }
    return 0;
}