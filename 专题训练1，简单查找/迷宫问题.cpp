#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include <stack>
#include<utility>

using namespace std;

const int maxn = 6;

int map [maxn][maxn];

struct point{
    int x , y , pos;
    pair<int ,int > p;
    point(){};
    point(int a,int b,int c) : x(a),y(b),pos(c) {}
    point move(int i) {
        point tmp = *this;
        switch (i) {
            case 0: {
                tmp.x += 1;
                break;
            }
            case 1: {
                tmp.x -= 1;
                break;
            }
            case 2: {
                tmp.y += 1;
                break;
            }
            case 3: {
                tmp.y -= 1;
                break;
            }
        }
        return tmp;
    }
};


int main()
{
    point m[maxn][maxn];
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 5; j++) {
            cin >> map[i][j];
            m[i][j].x = i;
            m[i][j].y = j;
            m[i][j].pos = -1;
         }
    }
    queue<point>q;
    point beg(0,0,0);
    q.push(beg);
    
    while (!q.empty()) {
        point now = q.front();
        q.pop();
        //m[now.x][now.y].pos = now.pos;
        for (int i = 0; i < 4; i++) {
            point next = now.move(i);
            if (next.x < 5 && next.x >= 0 && next.y < 5 && next.y >= 0 
            && map[next.x][next.y] != 1 && m[next.x][next.y].pos == -1) {
                m[next.x][next.y].pos = now.pos+1;
                m[next.x][next.y].p = make_pair(now.x,now.y);
                q.push(m[next.x][next.y]);
            } 
        }
    }
    stack<pair<int ,int> > s;
    s.push(make_pair(4,4));
    pair<int,int>x = m[4][4].p;
    int y = m[4][4].pos;
    while (y --) {
        
        s.push(x);
        x = m[x.first][x.second].p;
    }
    while (!s.empty()) {
        x = s.top();
        s.pop();
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }
}