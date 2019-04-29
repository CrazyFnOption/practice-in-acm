#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int maxn = 100005;

bool vis[maxn];
int N,K;

struct Node {
    int x,step;
    Node () {}
    Node (int a,int b) :x(a),step(b){};
    Node move(int i) {
        Node tmp(x,step);
        switch (i) {
            case 0: {
                tmp.x = x + 1;
                break;
            }
            case 1: {
                tmp.x = x - 1;
                break;
            }
            case 2 : {
                tmp.x = x * 2;
                break;
            }
        }
        tmp.step ++;
        return tmp;
    }
};

int bfs (int a,int b) {
    queue<Node> q;
    Node now(a,0),next;
    q.push(now);
    vis[now.x] = true;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0 ; i < 3 ; i++) {
            next = now.move(i);
            if (next.x >= 0 && next.x <= 100000 && !vis[next.x])
            {
                vis[next.x] = true;
                q.push(next);
            }
            if (next.x == b)
                return next.step;
        }
    }
    return -1;
}

int main() 
{
    while (~scanf("%d %d",&N,&K)) {
        if (N == K) printf("0\n");
        else {
            memset(vis,false,sizeof vis);
            printf("%d\n",bfs(N,K));
        }
    }



    return 0;
}
