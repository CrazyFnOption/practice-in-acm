/*************************************************************************
	> File Name: 棋盘问题.cpp
	> Author: wangshuxiao
	> Mail: wsx1128@outlook.com 
	> Created Time: Sun  3 Mar 15:05:54 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n,k;
char board  [10][10];
int total;
bool booked[10];
int  cnt;

void dfs(int  cur) {
	if (cnt == k) {
		total ++;
		return;
	}
	if (cur >= n) return ;
	for (int j = 0; j < n; j ++) {
		if (booked[j] == false && board[cur][j] == '#') {
			booked[j] = true;
			cnt ++;
			dfs(cur + 1);
			booked[j] = false;
			cnt --;
		}
	}
	//这种情况是防范 没有在首置位 有满足符合条件的数据
	dfs(cur + 1);
}


int main()
{
   
   while (cin >> n >> k) {
	   if (n ==  -1 && k == -1) break;
	   
	   for (int i = 0; i < n;  i ++)  {
		   booked[i] = false;
		   for (int j = 0; j <  n; j ++) {
			   cin >> board[i][j];
		   }
	   }
	   total = 0,cnt = 0;
	   dfs(0);
	   cout << total << endl;
   }
    return 0;
}

