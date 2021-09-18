#include <stdio.h>
void move(char a, char b);
void Hanoi(int n, char x, char y, char z);
int main()
{
	int n;
	printf("please input the number of plates:\n");
	scanf("%d", &n);
	printf("The movement route of plate:\n");
	Hanoi(n,'A', 'B', 'C');
}
void move(char a, char b)
{
	printf("%c->%c\n", a, b);
}

void Hanoi(int n, char x, char y, char z)		
{
	if (1 == n)
		move(x, z);
	else
	{
		Hanoi(n - 1, x, z, y);	
		move(x, z);		
		Hanoi(n - 1, y, x, z);	
	}
}