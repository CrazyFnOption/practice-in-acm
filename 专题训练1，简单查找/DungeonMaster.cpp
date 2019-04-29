/*************************************************************************
	> File Name: DungeonMaster.cpp
	> Author: wangshuxiao
	> Mail: wsx1128@outlook.com 
	> Created Time: Sun  3 Mar 16:10:18 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>


using namespace std;

const int maxn = 35;

int L,C,R;
char map[maxn][maxn][maxn];
int dis[maxn][maxn][maxn];

struct position {
	int x,y,z;
	int pos;
	position () = default;
	position(int x,int y,int z,int pos) :  this.x(x),
	this.y(y),this.z(z),this.pos(pos) {};
	position move (int i);
};

position position::move(int i)
{
    position tmp = *this;
    switch (i)
    {
    case 1:
        tmp.x = x + 1;
        break;
    case 2:
        tmp.x = x - 1;
        break;
    case 3:
        tmp.y = y + 1;
        break;
    case 4:
        tmp.y = y - 1;
        break;
    case 5:
        tmp.z = z + 1;
        break;
    case 6:
        tmp.z = z - 1;
        break;
    }
    return tmp;
}

void bfs (int i,int j,int k) {
	position beg (i,j,k,0);
	queue<position> q;
	q.push(beg);
	while (!q.empty()) {
		position now = q.front();
		q.pop();
		dis[now.x][now.y][now.z] = now.pos;
		for (int i = 0; i < 7; i++) {
			position next = now.move(i);
			if (next.x >= 0 && next.x < L && next.y >= 0 && next.y < R
            && next.z >= 0 && next.z < C && dis[next.x][next.y][next.z]
			== -1 && map[next.x][next.y][next.z] != '#') {
				position empt (next.x,next.y,next.z,now.pos + 1);
				q.push(empt);
			}
		}
	}
}

int main()
{
	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0) {
			break;
		int x1,y1,z1;
		int x2,y2,z2;

	for (int i = 0; i != L; i++)
        {
            for (int j = 0; j != R; j++)
            {
                for (int k = 0; k != C; k++)
                {
                    cin >> map[i][j][k];
                    dis[i][j][k] = -1;
                    if (map[i][j][k] == 'S')
                    {
                        x1 = i;
                        y1 = j;
                        z1 = k;
                    }
                    if (map[i][j][k] == 'E')
                    {
                        x2 = i;
                        y2 = j;
                        z2 = k;
                    }
                }
            }
        }
     bfs(x1, y1, z1);
	if (dis[x2][y2][z2] == -1)
        cout << "Trapped!" << endl;
    else {
        cout << "Escaped in " << dis[x2][y2][z2] << " minute(s)." << endl;
    }
    return 0;
}

