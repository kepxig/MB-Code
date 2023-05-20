/*
【问题描述】
合并排序是用分治策略实现对n个元素进行排序的算法。其基本思想是：将待排序元素分成大小大致相等的两个子集合，分别对两个子集合进行排序，最终将排好序的子集合合并成所要求的排好序的子集合。
输入n个整数，用合并排序算法对n个整数进行排序后输出。

【输入形式】
有两行输入，第一行为一个整数n，第二行为n个整数

【输出形式】
n个排序后的整数。

【样例输入】
5
12 5 33 8 16

【样例输出】
5 8 12 16 33
*/
#include <stdio.h>
#include <stdlib.h>

// 合并两个有序序列
void merge(int *A, int left, int mid, int right) {
    int *B = (int *)malloc((right - left + 1) * sizeof(int)); // 临时数组
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= right) {
        B[k++] = A[j++];
    }
    for (k = 0, i = left; i <= right; k++, i++) {
        A[i] = B[k];
    }
    free(B);
}

// 归并排序
void merge_sort(int *A, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    merge_sort(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    free(A);
    return 0;
}
