#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 10010;
bool check[maxn];
int prime[maxn];
bool vis[maxn];
int tot = 0;
int beg,res;
void get_prime() {
    memset(check,0,sizeof check);
    
    for (int i = 2; i < maxn; i++) {
        if (!check[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

struct Node
{
    int val, step;
    Node(){};
    Node(int a, int b) : val(a), step(b){};
};

int bfs() {
    queue<Node> q;
    q.push(Node(beg,0));
    memset(vis,0,sizeof vis);
    vis[beg] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.val == res) return now.step;
        int b[4];
        b[0] = now.val / 1000;
        b[1] = now.val / 100 % 10;
        b[2] = now.val / 10 % 10;
        b[3] = now.val % 10;

        for (int i = 0; i < 4; i++) {
            //注意一下 先开始这个地方是写错了 不能这样写的原因就在于不能每次经过一个更变的循环后 就会改变其原来的值
            
            int ss = b[i];
            for (int j = 0; j < 10; j++) {
                b[i] = j;
                int tmp = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
                if ( tmp >= 1000 && tmp <= 9999 && !vis[tmp] && !check[tmp]) {
                    vis[tmp] = true;
                    q.push(Node(tmp,now.step + 1));
                }
            }
            b[i] = ss;
        }

    }
    return -1;
}
int main()
{
    get_prime();
    int T;
    cin >> T;
    while (T --) {
        cin >> beg >> res;
        int ans = bfs();
        if (ans == -1) cout << "Impossible" << endl;
        cout << ans << endl;
    }
    return 0;
}