#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, j, n, temp;
	printf("����Ԫ�صĸ�����");
	scanf("%d", &n);
	int a[n]; 
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]); //ѭ������n����
	for (i = 0; i < n; i++) //ѭ���ж�������ÿһ����
	{
		for (j = i + 1; j < n; j++) //�ж�a[i]��ߵ����Ƿ��a[i]���
		{
			if (a[i] == a[j])
			{
				for (temp = j; temp < n; temp++)
					a[temp] = a[temp + 1]; //��a[j]�����Ԫ��ȫ��ǰ��һ��λ��
				j--;					   //a[j+1]ȡ��a[j]λ�ã�Ϊʹ�´δ�a[j+1]��ʼ����,j��һ(Ϊʹj���ֲ���)
				n--;					   //���鳤�ȼ�һ
			}
		}
	}
	printf("ʣ��Ԫ�ظ���: %d\n", n);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
	return 0;
}
