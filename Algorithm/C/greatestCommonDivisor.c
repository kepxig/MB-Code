#include <stdio.h>
int greatestCommonDivisor(int a, int b)
{
	int out;
	for (int i = 1; i <= a && i <= b; i++)
	{
		if ((a % i == 0) && (b % i == 0))
			out = i;
	}
	return out;
}
int main()
{
	int a, b;
	printf("PLEASE INPUT 2 INTEGERS:\n");
	scanf("%d%d", &a, &b);
	int out = greatestCommonDivisor(a, b);
	printf("%d", out);
	return 0;
}