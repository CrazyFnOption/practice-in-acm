#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<iterator>
using namespace std;

int A,B,C;

const int maxn = 1005;
bool vis[maxn][maxn];

const string s[6] = {"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};


struct Node
{
    int v_a,v_b;
    int step;
    vector<string> vs;
    Node() {};
    Node (int a,int b,int c) : v_a(a), v_b(b), step(c) {
    }
};

bool bfs() {
    queue<Node> q;
    Node now(0,0,0),next;
    vis[0][0] = true;
    q.push(now);
    vector<string> * tmp;
    while(!q.empty()) 
    {
        Node now = q.front();
        q.pop();
        
        if (now.v_a == C || now.v_b == C) {
            cout << now.step << endl;
            for (int it = 0; it != now.vs.size(); it++) {
                cout << now.vs[it] << endl;
            }
            return true;
        }

        if (now.v_a != A) {
            next.v_a = A;
            next.v_b = now.v_b;
            next.step = now.step + 1;
            
            if (!vis[next.v_a][next.v_b]){
                vis[next.v_a][next.v_b] = true;
                next.vs = now.vs;
                next.vs.push_back(s[0]);
                q.push(next);
            }
            
        }

        if (now.v_b != B) {
            next.v_b = B;
            next.v_a = now.v_a;
            next.step = now.step + 1;
            
            if (!vis[next.v_a][next.v_b])
            {
                vis[next.v_a][next.v_b] = true;
                next.vs = now.vs;
                next.vs.push_back(s[1]);
                q.push(next);
            }
        }

        if (now.v_a != 0){
            next.v_a = 0;
            next.v_b = now.v_b;
            next.step = now.step + 1;
            
            if (!vis[next.v_a][next.v_b])
            {
                vis[next.v_a][next.v_b] = true;
                next.vs = now.vs;
                next.vs.push_back(s[2]);
                q.push(next);
            }
        }

        if (now.v_b != 0){
            next.v_b = 0;
            next.v_a = now.v_a;
            next.step = now.step + 1;
           
            if (!vis[next.v_a][next.v_b])
            {
                vis[next.v_a][next.v_b] = true;
                next.vs = now.vs;
                next.vs.push_back(s[3]);
                q.push(next);
            }
        }

        if (now.v_a != 0 && now.v_b != B) {
            next.v_a = now.v_a - (B - now.v_b);
            next.v_b = now.v_a + now.v_b;
            if (next.v_b > B) next.v_b = B;
            if (next.v_a < 0) next.v_a = 0;
            next.step = now.step + 1;
            
            if (!vis[next.v_a][next.v_b])
            {
                vis[next.v_a][next.v_b] = true;
                next.vs = now.vs;
                next.vs.push_back(s[4]);
                q.push(next);
            }
        }

        if (now.v_a != A && now.v_b != 0){
            next.v_b = now.v_b - (A - now.v_a);
            next.v_a = now.v_a + now.v_b;
            if (next.v_a > A) next.v_a = A;
            if (next.v_b < 0) next.v_b = 0;
            next.step = now.step + 1;
            
            if (!vis[next.v_a][next.v_b])
            {
                vis[next.v_a][next.v_b] = true;
                next.vs = now.vs;
                next.vs.push_back(s[5]);
                q.push(next);
            }
        }
        
    }
    return false;
}


int main()
{
    while(cin >> A >> B >> C) {
        memset(vis,false,sizeof vis);
        if (!bfs()) cout << "impossible" << endl;
    }
    return 0;
}