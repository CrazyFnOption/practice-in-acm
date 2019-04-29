#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
    double v, w, c;
    bool operator < (const Node & n) const {
        return c > n.c;
    }
} node[1000 + 10];

int main()
{
    int m, n;
    while (cin >> m >> n && n != -1 && m != -1)
    {
        memset(node, 0, sizeof(node));
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].v >> node[i].w;
            node[i].c = node[i].v / node[i].w;
        }
        double sum = 0;
        sort(node,node + n);
        int i = 0;
        while (m > 0 && i < n)
        {
            if (m >= node[i].w)
            {
                m -= node[i].w; 
                sum += node[i].v;
                i++;
            }
            else
            {
                sum += m * node[i].v / node[i].w; 
                m = 0;
            }
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}