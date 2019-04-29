/*
	关于这道题目使用了康拓展开以及相应的a*算法，关于这道题目有意思的一点就在于康拓展开里面的状态压缩
    以及对于状态压缩所进行的处理，我觉得在这个地方是值得深度研究的。
    并且 关于a*算法中的曼哈顿距离这里都是值得去深究的。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>


using namespace std;
int beg[10];
char tt[10];
int now;

string op;

struct Node {
    int s[9];
    int cur,n;
    int f, g, h;
    Node(){}
    
    //这里交换位置的意图就这样体现出来了，意思就在于使最小的出去（这道题的意思就是使其变成小顶堆）
    //而不是使最小的出去 c++中的优先队列默认使最大的出去。（默认就是大顶堆）
    bool operator < (const Node &n) const {
        if (f != n.f) return n.f < f;
        return n.g < g;
    }
}o;

int fac[] = {1,1,2,6,24,120,720,5040,40320};

//这里就是康拓展开相应的详解 意思就是 序列到自然数的映射
//一般用于全排列类型的状态压缩
//意思就是在相应的全排列的数字 进行计算每一个数字后面的比其小的数字 并且乘以相应的阶乘。
//比如 1 2 3 4 5 这个排列中  计算 3 4 1 5 2 计算公式如下：
// X = 2 * 4! + 2 * 3! + 0 * 2! + 1 * 1! + 0 * 0!
//= > X = 61 

int cantor(int s[])
{
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++) {
            if (s[j] < s[i]) cnt ++;
        }
        sum += cnt * fac[9 - i - 1];
    }
    return sum;
}
//而逆康拓展开则是 从自然数到序列的映射

/*

	过程如下：
    在（1，2，3，4，5) 给出61可以算出起排列组合为34152
具体过程如下：
用 61 / 4! = 2余13，说明 ,说明比首位小的数有2个，所以首位为3。
用 13 / 3! = 2余1，说明 ，说明在第二位之后小于第二位的数有2个，所以第二位为4。
用 1 / 2! = 0余1，说明 ，说明在第三位之后没有小于第三位的数，所以第三位为1。
用 1 / 1! = 1余0，说明 ，说明在第二位之后小于第四位的数有1个，所以第四位为5。

void DeCantor(int pos,int *x){
    set<int> st;
    for(int i=1;i<=N;++i){
        st.insert(i);
    }
    for(int i=1;i<=N;++i){
        int r = pos / Fac[N-i];
        int l = pos % Fac[N-i];
        pos = l;
        set<int>::iterator it;
        int Count = 0;
        for(it = st.begin();it != st.end();++it){
            Count++;
            if(Count == r+1){
                break;
            }
        }
        x[i] = *it;
        st.erase(it);
    }
}

*/

//这里就是求曼哈顿距离
int get_h (int *s) {
    int val = 0;
    for (int i = 0; i < 9; i++) {
        int x = i / 3;
        int y = i % 3;
        if (s[i]) {
            int tx = (s[i] - 1) / 3;
            int ty = (s[i] - 1) % 3;
            val += abs(x - tx) + abs(y -ty);
        }
    }
    return val;
}

int vis[400000];
int front[400000];
char path[400000];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
string D = "dulr";

void disp(int n) {
    if (front[n]) {
        disp(front[n]);
        cout << path[n];
    }
}

void A_star() {
    memset(vis,0,sizeof vis);
    memset(front,0,sizeof front);
    priority_queue<Node> q;
    q.push(o);
    vis[o.n] = 1;
    int ans = 46233;
    while (!q.empty()) {
        Node tmp = q.top();
        if (tmp.n == ans) {
            disp(ans);
            cout << endl;
            return ;
        }
        q.pop();
        int x = tmp.cur / 3;
        int y = tmp.cur % 3;
        for (int p = 0; p < 4; p++) {
            int tx = dir[p][0] + x;
            int ty = dir[p][1] + y;
            if (tx < 0 || ty < 0 || tx > 2 || ty > 2) continue;
            Node next = tmp;
            next.cur = tx * 3 + ty;
            swap(next.s[tmp.cur],next.s[next.cur]);
            next.n = cantor(next.s);
            if (vis[next.n]) continue;
            vis[next.n] = 1;
            front[next.n] = tmp.n;
            path[next.n] = D[p];
            next.g++;
            next.h = get_h(next.s);
            next.f = next .g + next.h;
            q.push(next);
        }
    }

}

int main()
{
    char ch;
    while (cin >> ch) {
        if (ch == 'x') {
            ch = '0';
            o.cur = 0;
        }
    
        o.s[0] = ch - '0';
        for (int i = 1; i < 9; i++) {
            cin >> ch;
            if (ch == 'x') {
                ch = '0';
                o.cur = i;
            }
            o.s[i] = ch - '0';
        }
        o.n = cantor(o.s);
        o.g = 0;
        o.h = get_h(o.s);
        o.f = o.g + o.h;
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (o.s[i]) {
                for (int j = i + 1; j < 9; j++) {
                    if (o.s[j] < o.s[i] && o.s[j]) cnt ++;
                }
            }
        }
        if (cnt & 1) cout << "unsolvable" << endl;
        else A_star();
    }
    return 0;
}