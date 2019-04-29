#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

const  int maxn = 1000010;
bool check[maxn];
int prime [maxn];
int prime2 [maxn];

void fun()
{
    memset(prime,0,sizeof prime);
    for (int i = 2; i <= maxn; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > maxn) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void getPrime(int left,int right) {
    memset(check,1,sizeof check);
    if (left < 2) left = 2;
    for (int i = 1; i <= prime[0] && (long long)prime[i] * prime[i] <= right; i++) {
        int s = left / prime[i] + (left % prime[i] > 0);
        if (s == 1) s = 2;

        for (int j = s;(long long) j * prime[i] <= right;j++) {
            if ((long long)j * prime[i] >= left) 
            //这里之所以减去一个数组的左半边的原因就在于 题目给出的数据范围是完全没有办法达到的。
            check[j * prime[i] - left] = false;
        }
    }
    prime2[0] = 0;
    for (int i = 0; i <= right - left; i++) {
        if (check[i]) prime2[++prime2[0]] = i + left;
    }
}




int main()
{
    fun();
    int left,right;
    while(scanf("%d%d",&left,&right) != EOF) {
        getPrime(left,right);
        if (prime2[0] < 2)
            printf("There are no adjacent primes.\n");
        else {
            int x1 = 0;
            int x2 = 1000000;
            int y1 = 0, y2 = 0;
            for (int i = 1; i < prime2[0]; i++) {
                if (prime2[i + 1] - prime2[i] < x2 - x1) {
                    x1 = prime2[i];
                    x2 = prime2[i + 1];
                }
                if(prime2[i+1]-prime2[i]>y2-y1)
                {
                    y1=prime2[i];
                    y2=prime2[i+1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",x1,x2,y1,y2);
        }
    }

}