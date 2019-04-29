#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
int T;
int a, b;

const int maxn = 10000;
int prime[maxn];
bool check[maxn];
int v[maxn];
int tot = 0;

void get_prime()
{
    memset(check, false, sizeof(check));
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > maxn)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main () 
{
    get_prime();
    int t = 0;
    for (int i = 0;i < maxn; i ++)
        cout << prime[i] << '\t';
        
    
}
