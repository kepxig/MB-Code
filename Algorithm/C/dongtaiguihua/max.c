#include <stdio.h>
#define MAX_N 1000

int main() {
    int n, coins[MAX_N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &coins[i]);
    }

    // 用选择排序找到最大值
    int max_coin = coins[0];
    for (int i = 1; i < n; ++i) {
        if (coins[i] > max_coin) {
            max_coin = coins[i];
        }
    }

    printf("%d\n", max_coin);
    return 0;
}