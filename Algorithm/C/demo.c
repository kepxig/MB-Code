// 通过递归法求解正整数分解式数
#include <stdio.h>

int solve(int n)
{
    int ans = 1, i;
    for (i = 2; i * i < n; i++) {           // 因子乘因子小于n
        if (n % i == 0) {                  // 当i是n的因子时
            ans += solve(i) + solve(n / i); // ans加上i和n/i两种情况的分解式个数
        }
    }
    if (i * i == n) {                       // i * i 等于n时只有一种情况，左右交换也是一种
        ans += solve(i);                   // ans加上这种情况的分解式个数
    }
    return ans;                             // 返回总的分解式个数
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));               // 输出分解式总数
    return 0;
}