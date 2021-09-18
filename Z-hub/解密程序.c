#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, i, arr[4];
    printf("Please input a 4-digit number you wish to unencrypt:\n");
    scanf("%d", &x);
    if (x >= 1000 && x <= 9999)
    {
        arr[0] = x / 1000;
        arr[1] = x % 1000 / 100;
        arr[2] = x % 100 / 10;
        arr[3] = x % 10;
        for (i = 0; i <= 3; i++)
        {
            if (arr[i] <7)
            {
                arr[i] += 3;
            }
            else
            {
                arr[i] -= 7;
            }
        }
    }
    printf("The encrypted number is %04d", arr[2]*1000+arr[3]*100+arr[0]*10+arr[1]);

    system("pause");
    return 0;
}