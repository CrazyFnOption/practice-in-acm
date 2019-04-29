
#include <vector>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;

int n, m;
char map[201][201];
int dis_Y[201][201];
int dis_M[201][201];

struct point
{
    int x, y, pos;
    point(){};
    point(int a, int b, int c) : x(a), y(b), pos(c) {}
};

int _move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(queue<point> *q, int x, int y, bool flag)
{
    point beg(x, y, 0);
    q->push(beg);
    
    point now, next;
    while (!q->empty())
    {
        now = q->front();
        q->pop();
        for (int i = 0; i < 4; i++)
        {
            next.x = now.x + _move[i][0];
            next.y = now.y + _move[i][1];
            if ( next.x < n && next.x >= 0 && next.y < m && next.y >= 0 && map[next.x][next.y] != '#')
            {
                if (flag)
                {
                    if (dis_Y[next.x][next.y] == -1)
                    {
                        next.pos = now.pos + 1;
                        q -> push(next);
                        dis_Y[now.x][now.y] = now.pos + 1; 
                    }
                }
                else
                {
                    if (dis_M[next.x][next.y] == -1)
                    {
                        next.pos = now.pos + 1;
                        q -> push(next);
                        dis_M[now.x][now.y] = now.pos + 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int yi_x, yi_y;
    int m_x, m_y;
    while (~scanf("%d %d", &n, &m))
    {
        pair<int,int> p;
        getchar();
        vector<pair<int,int> >v;
        queue<point> qm;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%c", &map[i][j]);
                dis_M[i][j] = -1;
                dis_Y[i][j] = -1;
                
                if (map[i][j] == 'Y')
                {
                    yi_x = i;
                    yi_y = j;
                }

                else if (map[i][j] == 'M')
                {
                    m_x = i;
                    m_y = j;
                }
                else if (map[i][j] == '@')
                {
                    
                    v.push_back(make_pair(i,j));
                }
            }
            getchar();
        }
        dis_Y[yi_x][yi_y] = 0;
        dis_M[m_x][m_y] = 0;
        bfs(&qm, yi_x, yi_y, true);
        bfs(&qm, m_x, m_y, false);

        

        int Min = 9999999;
        int tmp = 0;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            tmp = dis_M[it->first][it->second] + dis_Y[it->first][it->second];
            if (Min > tmp)
                Min = tmp;
        }
        printf("%d\n", Min * 11);
    }
    return 0;
}