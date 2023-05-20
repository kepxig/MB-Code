#include <stdio.h>
#define MAXSIZE 1000
int sumOfIntegers(int n, int *arr)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
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
	printf("%d", sumOfIntegers(n, arr));
	return 0;
}