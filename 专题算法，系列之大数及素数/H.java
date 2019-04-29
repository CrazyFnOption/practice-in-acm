import java.util.Scanner;

import java.math.BigInteger;


public class H {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        BigInteger a;
        String b,c;
        int Case = 1;
        while (cin.hasNext()) {
            
            a = cin.nextBigInteger();
            b = a.mod(new BigInteger("137")).toString();
            c = a.mod(new BigInteger("73")).toString();
            if (b.equals("0") && c.equals("0") )   System.out.println("Case #" + Case++ + ": YES");
            else System.out.println("Case #" + Case++ + ": NO");
        }

    }
}

/*
关于这道题，不知道为什么用java 提交就是没有办法过，全部都是爆内存，我个人觉得可能在大数，求余数这方面，可能存在缺陷。
下面提供几个 AC的 C++代码


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10000000 + 1;
const int mod = 10001;
char s[maxn];
int main(){
    int kase = 0;
    while(scanf("%s",s) == 1){
        int len = strlen(s);
        int v = 0;
        for (int i = 0; i < len; ++i){
            v = (v*10 + s[i]-48) % mod;
        }
        if (v == 0)printf("Case #%d: YES\n",++kase);
        else printf("Case #%d: NO\n",++kase);
    }
    return 0;
}



*/

