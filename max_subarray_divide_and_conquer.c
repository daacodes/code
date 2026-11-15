#include <stdio.h>

int max2(int a, int b) { return (a > b) ? a : b; }
int max3(int a, int b, int c) { return max2(max2(a, b), c); }

// find crossing maximum subarray
int max_cross_sum(int a[], int l, int m, int h) {
    int sum = 0, left_sum = -1e9;
    for (int i = m; i >= l; i--) {
        sum += a[i];
        if (sum > left_sum) left_sum = sum;
    }
    sum = 0;
    int right_sum = -1e9;
    for (int i = m + 1; i <= h; i++) {
        sum += a[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

// divide and conquer solver
int max_subarray(int a[], int l, int h) {
    if (l == h) return a[l];
    int m = (l + h) / 2;
    return max3(max_subarray(a, l, m),
                max_subarray(a, m + 1, h),
                max_cross_sum(a, l, m, h));
}

int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int ans = max_subarray(a, 0, n - 1);
    printf("Maximum subarray sum: %d\n", ans);
    return 0;
}
