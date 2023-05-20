#include <string.h>

#include <stdlib.h>

void intersection(int *A, int *B, int lenA, int lenB, int **C, int *lenC)
{
	/*

	A表示数组A，B表示数组B，lenA表示数组A的长度，lenB表示数组
	B的长度，C表示结果，lenC表示结果的长度
	需要将交集存放在数组C中。
  */

	/*********Begin********/
	for (int i = 0; i < lenA; i++)
	{
		if (A[i])
			C[A[i]] += 1;
	}
	/*for (int i = 0; i < lenB; i++)

	{
	}
	/*********End*********/
}
int main()
{
	int A[] = {1, 2, 0, 2, 1};
	int B[] = {2, 3, 6, 7};
	int lenA = sizeof(A);
	int lenB = sizeof(B);
	int C[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int lenC = sizeof(C);
	intersection(A, B, lenA, lenB, C, lenC);
	for (int i = 0; i < lenC; i++)
	{
		print("%d", C[i]);
	}
	return 0;
}