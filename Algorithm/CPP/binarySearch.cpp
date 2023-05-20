#include <iostream>
using namespace std;
//ʵ�ֶ��ֲ����㷨��ele ��ʾҪ���ҵ�Ŀ��Ԫ�أ�[p,q] ָ����������
int binary_search(int *arr, int p, int q, int ele)
{
    int mid = 0;
    //���[p,q] �����ڣ����� -1
    if (p > q)
    {
        return -1;
    }
    // �ҵ��м�Ԫ�����ڵ�λ��
    mid = p + (q - p) / 2;
    //�ݹ�ĳ���
    if (ele == arr[mid])
    {
        return mid;
    }
    //�Ƚ� ele �� arr[mid] ��ֵ����С ele ���ܴ��ڵ�����
    if (ele < arr[mid])
    {
        //�µ���������Ϊ [p,mid-1]
        return binary_search(arr, p, mid - 1, ele);
    }
    else
    {
        //�µ���������Ϊ [mid+1,q]
        return binary_search(arr, mid + 1, q, ele);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    printf("%d", binary_search(a, 0, n, k));
    return 0;
}
/*
5 13
1 2 13 45 12
2
*/