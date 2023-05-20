/*
|0Description
大于1的正整数n可以分解为：n=x1 * x2 * … * xm。 例如，当n=12 时，共有8 种不同的分解式：
 12=12； 12=6 * 2； 12=4 * 3； 12=3 * 4； 12=3 * 2 * 2； 12=2 * 6； 12=2 * 3 * 2； 12=2 * 2 * 3。 
 对于给定的正整数n，计算n共有多少种不同的分解式。

2|0Input
输入数据只有一行，有1个正整数n (1≤n≤2000000000)。

3|0Output
将计算出的不同的分解式数输出。

4|0Sample Input
12
5|0Sample Output
8
*/// 通过递归法求解正整数分解式数
#include <stdio.h>

int solve(int n)
{
    int ans = 1, i;
    for (i = 2; i * i < n; i++)
    { // 因子乘因子小于n
        if (n % i == 0)
        {                                   // 当i是n的因子时
            ans += solve(i) + solve(n / i); // ans加上i和n/i两种情况的分解式个数
        }
    }
    if (i * i == n)
    {                    // i * i 等于n时只有一种情况，左右交换也是一种
        ans += solve(i); // ans加上这种情况的分解式个数
    }
    return ans; // 返回总的分解式个数
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n)); // 输出分解式总数
    return 0;
}