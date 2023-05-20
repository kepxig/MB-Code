#include <iostream>
using namespace std;
#define MAXSIZE 100
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void perm(int a[], int m, int n) //数组存放排列的数，m表示层 代表第几个数，n表示数组的长度
{
    if (m == n)
    { // m==n 表示到达最后一个数，不能再交换，最终的排列的数需要输出；
        for (int i = 0; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
    {
        for (int i = m; i <= n; i++)
        {
            swap(a[i], a[m]);
            perm(a, m + 1, n);
            swap(a[i], a[m]);
        }
    }
}
int main()
{
    int n, a[MAXSIZE];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i - 1] = i;
    }
    perm(a, 0, n - 1);
    return 0;
}