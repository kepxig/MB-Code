/*
������������
�ϲ��������÷��β���ʵ�ֶ�n��Ԫ�ؽ���������㷨�������˼���ǣ���������Ԫ�طֳɴ�С������ȵ������Ӽ��ϣ��ֱ�������Ӽ��Ͻ����������ս��ź�����Ӽ��Ϻϲ�����Ҫ����ź�����Ӽ��ϡ�
����n���������úϲ������㷨��n��������������������

��������ʽ��
���������룬��һ��Ϊһ������n���ڶ���Ϊn������

�������ʽ��
n��������������

���������롿
5
12 5 33 8 16

�����������
5 8 12 16 33
*/
#include <stdio.h>
#include <stdlib.h>

// �ϲ�������������
void merge(int *A, int left, int mid, int right) {
    int *B = (int *)malloc((right - left + 1) * sizeof(int)); // ��ʱ����
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

// �鲢����
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
