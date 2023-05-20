#include <stdio.h>
#define MAXSIZE 1000
int maximumOfIntegers(int n, int *arr)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
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
    int arr[MAXSIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", maximumOfIntegers(n, arr));
    return 0;
}