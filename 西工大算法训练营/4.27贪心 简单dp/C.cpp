#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int id;
    int _beg, _end;
    bool operator<(const Node &n) const
    {
        if (_end == n._end)
            return _beg > n._beg;
        return _end < n._end;
    }
} node[100000 + 5];

vector<int>v;

int main()
{
    int n;
    while (cin >> n && n)
    {
        v.clear();

        for (int i = 1; i <= n; i++)
        {
            cin >> node[i]._beg >> node[i]._end;
            node[i].id = i;
        }

        sort(node + 1, node + 1 + n);

        int tmp = node[1]._end;
        v.push_back(node[1].id);

        for (int i = 2; i <= n ; i++) {
            if (tmp < node[i]._beg) {
                tmp = node[i]._end;
                v.push_back(node[i].id);
            }
        }
        int i;
        for (i = 0; i < v.size() - 1; i++) {
            cout << v[i] << " ";
        }
        cout << v[v.size() - 1] << endl;
    }

    return 0;
}