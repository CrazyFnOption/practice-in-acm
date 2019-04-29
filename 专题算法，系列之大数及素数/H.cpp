#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int mod1 = 73;
const int mod2 = 137;

/*     
在做题之前，先了解这样一些结论：
A*B % C = (A%C * B%C)%C
(A+B)%C = (A%C + B%C)%C

如 532 mod 7 =（500%7+30%7+2%7)%7;

当然还有

a*b mod c=(a mod c+b mod c)mod c;

如35 mod 3=((5%3)*(7%3))%3
*/


int main()
{
    string s;
    int Case = 1;
    while (cin >> s)
    {
        int a = 0,b = 0;
        for (int i = 0; i < s.size(); i++) {
            a = (a * 10 + s[i] - '0') % mod1;
            b = (b * 10 + s[i] - '0') % mod2;
        }
        if (!a && !b) cout << "Case #" << Case++ << ": YES" << endl;
        else cout << "Case #" << Case++ << ": NO" << endl;
    }
}