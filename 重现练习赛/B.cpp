#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n,k;
bool vis[100010];

struct Node {
    int val,step;
    Node(){};
    Node (int a,int b) : val(a),step(b){};
};

int main()
{
    while (cin >> n >> k) {

        memset(vis,false,sizeof vis);
        queue<Node> q;
        q.push(Node(n,0));
        vis[n] = true;
        
        while (!q.empty()) {
            Node now = q.front();
            q.pop();

            if (now.val == k) {
                cout << now.step << endl;
                break;
            }

            int tmp = now.val + 1;
            if (tmp >= 0 && tmp <= 100000 && !vis[tmp])
            {
                vis[tmp] = true;
                q.push(Node(tmp,now.step + 1));
            }
            
            tmp = now.val - 1;
            if (tmp >= 0 && tmp <= 100000 && !vis[tmp])
            {
                vis[tmp] = true;
                q.push(Node(tmp, now.step + 1));
            }

            tmp = now.val * 2;
            if (tmp >= 0 && tmp <= 100000 && !vis[tmp])
            {
                vis[tmp] = true;
                q.push(Node(tmp, now.step + 1));
            }
        }
    }
    return 0;
}