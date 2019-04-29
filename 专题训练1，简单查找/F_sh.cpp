#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n;
string a, b, res;
string tmp_a,tmp_b;
int total;

struct Node {
    string x;
    int step;
    Node(){}
    Node (string y,int s) : x(y),step(s) {}
};

string merge (string a, string b) {
    string s;
    int j = 0;
    for (int i = 0; i < n;i++) {
        s += b[j++];
        s += a[i];
    }
    return s;
}

void splict(string ss) {
    a = ss.substr(0,ss.size()/2);
    b = ss.substr(ss.size()/2,ss.size());
}

int bfs() {
    queue<Node>q;
    Node now(merge(a,b),1);
    q.push(now);
    while(!q.empty()) {
        now = q.front();
        q.pop();
        splict(now.x);
        Node next(merge(a,b),now.step + 1);
        if (next.x == res) return next.step;
        if (a == tmp_a && b == tmp_b) return -1;
        q.push(next);
    }

    return -1;
}



int main()
{
    int T;
    cin >> T;
    int cnt = 1;
    while (T--) {
        cin >> n;
        cin >> a >> b >> res;
        tmp_a = a;
        tmp_b = b;
        if (merge(tmp_a,tmp_b) == res) cout << cnt++ << 1 << endl;
        else cout << cnt++ << " " << bfs() << endl;
    }
    return 0;
}