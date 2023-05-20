/*
������������
��������n��Ԫ�صĶ�Ҽ���S��ÿ��Ԫ����S�г��ֵĴ�����Ϊ��Ԫ�ص����������ؼ�S������������Ԫ���س�Ϊ������
����s = {1��2��2��2��3��4��5}�����ؼ�S��������2��������Ϊ3��
���ڸ�������n����Ȼ����ɵĶ��ؼ�S������S����������������

��������ʽ��
��1�У�һ������n��Ϊ���ؼ�S��Ԫ�ظ�����
��2��n��������Ϊ���ؼ�S��n��Ԫ�أ�n��10000��

�������ʽ��
���С���1��Ϊ��������2��Ϊ����������ж�������������С���Ǹ���

���������롿
7
1 2 2 2 3 4 5

�����������
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