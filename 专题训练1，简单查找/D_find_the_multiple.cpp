#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int T;

long long bfs (int a) {
    queue<long long>q;
    long long now,next;
    now = 1;
    q.push(now);
    while(!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0 ; i < 2; i++) {
            if (i == 1) {
                next = now * 10 + 1;
            }
            else next = now * 10;
            if (next % a == 0){
                return next;
            }
            q.push(next);
        }
    }
    return -1;
}



int main() 
{
    while (cin >> T && T != 0) {
        cout << bfs(T) << endl;
    }
    return 0;
}