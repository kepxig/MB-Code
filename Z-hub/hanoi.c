#include <stdlib.h>
#include <stdio.h>
void move(char x, int i, char y) 
{
    printf("Move %d : from %c to %c\n", i, x, y);
}
int main()
{
    void hanoi(int n, char a, char b, char c);
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    system("pause");
    return 0;
} 
void hanoi(int n, char a, char b, char c)
{
    void move(char x, int i, char y); 
    if (n == 1)
        move(a, 1, b); 
    else
    {
        hanoi(n - 1, a, c, b); 
        move(a, n, b);
        hanoi(n - 1, c, b, a); 
    }
}
