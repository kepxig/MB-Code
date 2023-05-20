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
void perm(int a[], int m, int n) //���������е�����m��ʾ�� ����ڼ�������n��ʾ����ĳ���
{
    if (m == n)
    { // m==n ��ʾ�������һ�����������ٽ��������յ����е�����Ҫ�����
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