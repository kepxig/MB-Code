#include <string.h>

#include <stdlib.h>

void intersection(int *A, int *B, int lenA, int lenB, int **C, int *lenC)
{
	/*

	A��ʾ����A��B��ʾ����B��lenA��ʾ����A�ĳ��ȣ�lenB��ʾ����
	B�ĳ��ȣ�C��ʾ�����lenC��ʾ����ĳ���
	��Ҫ���������������C�С�
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