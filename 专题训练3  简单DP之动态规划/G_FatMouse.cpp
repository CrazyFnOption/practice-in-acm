#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1005;

struct Mice {
    int id;
    int size;
    int speed;

    bool operator < (const Mice & that) const {
        if (size == that.size)
            return speed > that.speed;
        return size < that.size;
    }

}mice[maxn];

struct node {
    int pre;
    int num;
}dp[maxn];

int a,b,i;

void output(int x) {
    if (x == 0) return ;
    output(dp[x].pre);
    cout << mice[x].id << endl;
}

int main()
{
    int len = 1;
    while (cin >> a >> b) {
        mice[len].id = len;
        mice[len].size = a;
        mice[len].speed = b;
        len++;
    }
    sort(mice + 1,mice + len + 1);

    for (int j = 0 ; j <= len; j++) {
       dp[j].num = 1;
       dp[j].pre = 0;
    }
    int Max = 1;
    int index = 1;

    for (int j = 2 ; j < len; j++) {
        for (int k = 1; k < j; k ++) {
            if (mice[k].speed > mice[j].speed && mice[k].size < mice[j].size) {
                if (dp[j].num <= dp[k].num + 1) {
                    dp[j].num = dp[k].num + 1;
                    dp[j].pre = k;
                }
            }
        }
        if (Max < dp[j].num) {
            Max = dp[j].num;
            index = j;
        }
    }
    

    cout << Max <<endl;
    
    output(index);
    /*int m[1111];
    for (int i = 1; i <= Max ; i++) {
        m[i] = index;
        index = dp[index].pre;
    }
    for (int j = Max; j >=1 ;j--) {
        cout << mice[m[j]].id << endl;
    }*/
    
    return 0;
}