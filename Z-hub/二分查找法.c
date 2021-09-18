#include <stdio.h>
#include <stdlib.h>
int search(int a[], int n, int x);
int main()
{
    int key, n;
    scanf("%d", &n); //n

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    } //a[i]

    scanf("%d", &key); //key
    int index = search(a, n, key);
    if (!index)
    {

        printf("Value not found\n");
    }
    else
    {
        printf("Found value at index %d\n", index);
    }
    system("pause");
    return 0;
}
int search(int a[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (x < a[mid])
        {
            end = mid - 1;
        } //left part
        else if (x > a[mid])
        {
            start = mid + 1;
        } //right part

        else //x=a[mid]
        {
            return mid;
        }
    }
    return 0;
}