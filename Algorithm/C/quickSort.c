#include <stdio.h>
#include <stdlib.h>

void quick_sort(int nums[], int len) {
    if (len <= 1) {
        return;
    } else {
        int pivot = nums[0];
        int left_nums[len];
        int right_nums[len];
        int left_idx = 0;
        int right_idx = 0;
        for (int i = 1; i < len; ++i) {
            int num = nums[i];
            if (num < pivot) {
                left_nums[left_idx++] = num;
            } else {
                right_nums[right_idx++] = num;
            }
        }
        quick_sort(left_nums, left_idx);
        quick_sort(right_nums, right_idx);
        left_nums[left_idx] = pivot;
        for (int i = 0; i < right_idx; ++i) {
            left_nums[left_idx + i + 1] = right_nums[i];
        }
        for (int i = 0; i < len; ++i) {
            nums[i] = left_nums[i];
        }
    }
}

int main() {
    // 数组大小
    int n;
    scanf("%d", &n);
    // 输入数组
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, n);
    // 输出排序后的数组
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
