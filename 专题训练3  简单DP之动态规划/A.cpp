#include<iostream>
#include<map>
using namespace std;

int main()
{   
    int n,x,cnt;
    while (cin >> n) {
        map<int,int>m;
        for (int i = 0; i < n; i ++) {
            cin >> x;
            m[x]++;
            if (m[x] >= (n + 1) / 2) {
                cnt = x;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}