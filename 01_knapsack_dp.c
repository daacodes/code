#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

// 0-1 knapsack dynamic programming
int knapsack_dp(int wt[], int val[], int n, int cap) {
    int dp[50][100];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= cap; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][cap];
}

int main() {
    int n, cap, wt[50], val[50];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &wt[i], &val[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &cap);

    int max_val = knapsack_dp(wt, val, n, cap);
    printf("Maximum value in knapsack: %d\n", max_val);
    return 0;
}
