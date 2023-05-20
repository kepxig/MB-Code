#include <iostream>
using namespace std;
//实现二分查找算法，ele 表示要查找的目标元素，[p,q] 指定查找区域
int binary_search(int *arr, int p, int q, int ele)
{
    int mid = 0;
    //如果[p,q] 不存在，返回 -1
    if (p > q)
    {
        return -1;
    }
    // 找到中间元素所在的位置
    mid = p + (q - p) / 2;
    //递归的出口
    if (ele == arr[mid])
    {
        return mid;
    }
    //比较 ele 和 arr[mid] 的值，缩小 ele 可能存在的区域
    if (ele < arr[mid])
    {
        //新的搜索区域为 [p,mid-1]
        return binary_search(arr, p, mid - 1, ele);
    }
    else
    {
        //新的搜索区域为 [mid+1,q]
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