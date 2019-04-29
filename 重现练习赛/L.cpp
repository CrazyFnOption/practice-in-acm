#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n, x, cnt;
    while (~scanf("%d",&n))
    {
        
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            m[x]++;
            if (m[x] >= (n + 1) / 2)
            {
                cnt = x;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}