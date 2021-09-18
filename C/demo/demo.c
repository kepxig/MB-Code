#include <stdio.h>
#define N 10
typedef struct
{
	int a[N];
	int length;
} List;
int main()
{
	List L;
	int i, x;
	printf("length(1-10)=");
	scanf("%d", &L.length);
	printf("please enter numbers to list:");
	for (i = 0; i < L.length; i++)
		scanf("%d", &L.a[i]);
	printf("\nNumbers in List:");
	for (i = 0; i < L.length; i++)
		printf("%d ", L.a[i]);
	printf("\n%d\n",L.length);
	printf("please enter a number you want to insert into List:");
	scanf("%d", &x);
	if (!insert_a(&L, x))
		printf("No space!");
	else
	{
		printf("\nNumbers in List:");
		for (i = 0; i < L.length; i++)
			printf("%d ", L.a[i]);
		printf("\n");
	}
}

int insert_a(List *b, int e)
{
	int j;
	if (b->length + 1 > N)
		return 0;
	for (j = N - 1; j >= 0; j--)
	{
		if (e < b->a[j])
			b->a[j + 1] = b->a[j];
		else
			break;
		b->a[j + 1] = e;
		b->length++;
		return 1;
	}
}
