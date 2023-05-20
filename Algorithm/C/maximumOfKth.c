#include <stdio.h>
#define MAXSIZE 1000
void bubleSort(int n, int *arr)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1] > arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int maximumOfKth(int n, int *arr, int k)
{
    bubleSort(n,arr);
    return (arr[k-1]);
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n > MAXSIZE)
    {
        printf("ERROR:PLEASE INPUT A INTEGER LESS THAN %d !!\n", MAXSIZE);
        return 0;
    }
    int k;
    scanf("%d",&k);
    int arr[MAXSIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", maximumOfKth(n, arr,k));
    return 0;
}