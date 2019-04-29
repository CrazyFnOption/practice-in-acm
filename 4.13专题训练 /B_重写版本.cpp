#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int n,m,k;
const int maxn = 105;
char map[maxn][maxn];

int Min;
int cnt,total;
int res[5][2];
int beg_x,beg_y;


int main()
{
    while (cin >> n >> m) {
        if (n == 0 && m ==0) break;

        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <=m ; j++) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    beg_x = i;
                    beg_y = j;
                }
            }
        }

        
    }

    return 0;
}