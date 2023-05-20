#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
void numStatistics(int n)
{
    int out_arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char string[MAXSIZE] = {0};
    for (int i = 1; i <= n; i++) //书页从1开始 故i从1开始
    {
        // itoa(i, string, 10);
        /* ————整型转换为字符串 （整型，字符串，进制） but    
        itoa并不是一个标准的C函数，它是Windows特有的，如果要写跨平台的程序，请用sprintf，用法和printf相似。
        (在头歌平台用不了) 所以找到了下面的函数代替
        */
        sprintf(string, "%d", i);
        for (int j = 0; j < MAXSIZE; j++)
        {
            char ch = string[j]; //逐个字符判断
            switch (ch)
            {
            case '0':
                out_arr[0] += 1;
                break;
            case '1':
                out_arr[1] += 1;
                break;
            case '2':
                out_arr[2] += 1;
                break;
            case '3':
                out_arr[3] += 1;
                break;
            case '4':
                out_arr[4] += 1;
                break;
            case '5':
                out_arr[5] += 1;
                break;
            case '6':
                out_arr[6] += 1;
                break;
            case '7':
                out_arr[7] += 1;
                break;
            case '8':
                out_arr[8] += 1;
                break;
            case '9':
                out_arr[9] += 1;
                break;
            default:
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", out_arr[i]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    numStatistics(n);
    return 0;
}