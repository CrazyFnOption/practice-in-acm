#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
int T;
int a,b;

const int maxn = 10000;
int prime[maxn];
bool check[maxn];
bool vis[maxn];
int tot = 0;

struct Node {
    int x,step;
    Node(){};
    Node(int a,int c):x(a),step(c){}
};

void get_prime() {
    memset(check,false,sizeof(check));
    for (int i = 2; i < maxn ; i++) {
        if (!check[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int bfs(int a,int b) {
    memset(vis,false,sizeof vis);
    queue<Node> q;
    Node o1(a,0),o2,o3;
    q.push(o1);
    vis[a] = false;
    while(!q.empty()) {
        o2 = q.front();
        q.pop();
        if (o2.x == b) return o2.step;
        int num[4];
        num[0] = o2.x / 1000;
        num[1] = o2.x / 100 % 10;
        num[2] = o2.x / 10 % 10;
        num[3] = o2.x % 10;

        for (int i = 0; i < 4; i++) {
            int tmp = num[i];
            for (int j = 0; j < 10; j++) {
                num[i] = j;
                int yy = num[0] * 1000 + num[1] * 100 + num[2] *10 + num[3];
                if (!vis[yy] && !check[yy] && yy > 1000 && yy < 9999) {
                    vis[yy] = true;
                    o3.x = yy;
                    o3.step = o2.step + 1;
                    q.push(o3);
                }
            }
            num[i] =  tmp;
        }
    }
    return -1;
}



int main()
{
    get_prime();
    cin >> T;
    int ans = -1;
    while(T--) {
        cin >> a >> b;
        ans = bfs(a,b);
        if (ans == -1) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    
    return 0;
}