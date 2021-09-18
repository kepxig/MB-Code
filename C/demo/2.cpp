#include <stdio.h>
int main()
{
    int a[4][5] = {3, 16, 87, 65, 4, 32, 11, 108, 10, 25, 12, 37};
    int b[4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] > a[i + 1][j + 1])
                b[i] = a[i][j];
        }
    }
    for (int k = 0; k < 3; k++)
    {
        printf("%d ", b[k]);
    }
}
