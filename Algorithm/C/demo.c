// ͨ���ݹ鷨����������ֽ�ʽ��
#include <stdio.h>

int solve(int n)
{
    int ans = 1, i;
    for (i = 2; i * i < n; i++) {           // ���ӳ�����С��n
        if (n % i == 0) {                  // ��i��n������ʱ
            ans += solve(i) + solve(n / i); // ans����i��n/i��������ķֽ�ʽ����
        }
    }
    if (i * i == n) {                       // i * i ����nʱֻ��һ����������ҽ���Ҳ��һ��
        ans += solve(i);                   // ans������������ķֽ�ʽ����
    }
    return ans;                             // �����ܵķֽ�ʽ����
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));               // ����ֽ�ʽ����
    return 0;
}