#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

struct Subject {
    string name;
    int deadline;
    int finish;
    bool operator < (const Subject & s) const {
        if (deadline == s.deadline) return name < s.name;
        return deadline < s.deadline;
    }
}subject[17];

int dp[17];

int main()
{
    int T,n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> subject[i].name >> subject[i].deadline >> subject[i].finish;
        }
        sort(subject,subject + n);
        int cnt = 0,res = 0,_time = 0;
        for (int i = 0; i < n; i++) {
            cnt = subject[i].deadline - _time - subject[i].finish;
            if (cnt < 0) {
                res += -cnt;
                _time += subject[i].finish + -cnt;
            }
            else {
                _time += subject[i].finish;
            }
            
        }
        cout << res << endl;
        for (int i = 0 ; i < n; i++) {
            cout << subject[i].name << endl;
        }

    }
}