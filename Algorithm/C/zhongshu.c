/*
【问题描述】
给定含有n个元素的多币集合S，每个元素在S中出现的次数称为该元素的重数。多重集S中重述数最大的元素素称为众数。
例如s = {1，2，2，2，3，4，5}，多重集S的众数是2，其重数为3。
对于给定的由n个自然数组成的多重集S，计算S的众数及其重数。

【输入形式】
第1行，一个整数n，为多重集S的元素个数。
第2行n个整数，为多重集S的n个元素，n≤10000。

【输出形式】
两行。第1行为众数，第2行为重数。如果有多个众数，输出较小的那个。

【样例输入】
7
1 2 2 2 3 4 5

【样例输出】
2
3
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *S = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int max_count = 0, mode = S[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (S[j] == S[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = S[i];
        }
    }

    printf("%d\n%d", mode, max_count);
    free(S);
    return 0;
}