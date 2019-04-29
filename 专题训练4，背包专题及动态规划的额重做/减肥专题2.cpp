/*
	这道题其实是一道水题，但是刚开始看的时候 思路就是直接暴力搜，计算每一个值之间的间距，然后用相应的间距再去最后减去最后的总时间
    但是自己搞不清的地方就在于 应该是使用标记，这样一来轻松，而且也不怕重复了。
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2e3 + 5;
const int MAX = 5e5 + 5;
int _hash[N], a[MAX];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int HH, MM, H, M, sum = 0;
        sum = 24 * 60;
        memset(_hash, 0, sizeof(_hash));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d:%d", &HH, &MM);
            scanf("%d:%d", &H, &M);
            HH = HH * 60 + MM; //start time
            H = H * 60 + M;    // end time
            for (int i = HH; i < H; ++i)
            {
                if (!_hash[i])
                {
                    sum--;
                    _hash[i] = 1;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}