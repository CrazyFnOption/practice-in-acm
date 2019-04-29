#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1000005;
char s[maxn];
char tmp[1005];

vector <int> alp[27];

int main()
{
    scanf("%s",s);
    int n;
    int len = strlen(s);
    scanf("%d",&n);
    for (int k = 0;k < n; k++) {
        scanf("%s",tmp);
        int leng = strlen(tmp);
        int index , now = 0;

        int i,j;
        
        if (leng > len) {
            printf("NO\n");
            continue;
        }
        bool flag = true;
        for (i = 0;i < leng; i++) 
        {
            
            bool flagy = true;

            for (j = now; j < len;j++) 
            {

                if (s[j] == tmp[i]) {
                    now = j + 1;
                    flagy = false;
                    break;
                }

            }
            if (flagy == true) {
                printf("NO\n");
                flag = false;
                break;
            }
            
            
        }
        if (flag) printf("YES\n");
    }
    return 0;
}