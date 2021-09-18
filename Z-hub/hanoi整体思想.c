#include <stdio.h>
void move(char a, char b);
void Hanoi(int n, char x, char y, char z);
int main()
{
	int n;
	printf("please input the number of plates:\n");
	scanf("%d", &n);
	printf("The movement route of plate:\n");
	Hanoi(n, 'A', 'B', 'C');
}
void move(char a, char b)
{
	printf("%c->%c\n", a, b);
}

void Hanoi(int n, char x, char y, char z)		//数量、对象，介质，目标
{
	if (1 == n)
		move(x, z);
	else
	{
		Hanoi(n - 1, x, z, y);		//表示x柱上n-1个盘子移到y柱上借助z柱
		move(x, z);			//打印x->z的移动路线
		Hanoi(n - 1, y, x, z);		//表示y柱上n-1个盘子移到z柱上借助x柱
	}
}