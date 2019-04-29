#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 100005;
//三个属性值 一个重量 数量 以及价值
int weight[maxn],number[maxn],value[maxn];
//状态存储
int dp[maxn << 4];
//背包的容量
int bag; 
int n;

//01背包 
void zeroonepack(int weight,int value) {
    for (int j = bag; j >= weight; j--) {
        dp[j] = max(dp[j],dp[j - weight] + value);
    }
}
//完全背包
void completepack(int weight,int value) {
    for (int j = weight; j <= bag; j++) {
        dp[j] = max(dp[j],dp[j - weight] + value);
    }
}
//多重背包
void multilpack(int weight,int number,int value) {
    //第一种情况就是 如果这件物品所有的重量是小于背包的重量的话
    //那么对于背包而言 这个物品是可以取无限大。
    if (bag <= number * weight) {
        completepack(weight,value);
        return;
    }
    //而超过的这个范围的就只能使用01背包 然后使用二进制的方法
    //将每一类型的背包进行一个分组
    //后面再依次分别使用多重背包。
    int k = 1;
    while (k < number) {
        zeroonepack(k * weight,k * value);
        number = number - k;
        k = k * 2;
    }
    zeroonepack(number * weight, number * value);
}


int main()
{
    cin >> bag >> n;
    for (int i = 1; i <= n ;i ++) {
        cin >> weight[i] >> number[i] >> value[i];
    }

    for (int i = 1; i <= n ;i ++) {
        multilpack(weight[i],number[i],value[i]);
    }

    cout << dp[bag] << endl;

    return 0;
}