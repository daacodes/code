#include <stdio.h>

// kadane algorithm O(n)
int max_subarray_kadane(int a[], int n) {
    int max_so_far = a[0];
    int cur_max = a[0];
    for (int i = 1; i < n; i++) {
        cur_max = (a[i] > cur_max + a[i]) ? a[i] : cur_max + a[i];
        if (cur_max > max_so_far) max_so_far = cur_max;
    }
    return max_so_far;
}

int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // calculate max sum
    int ans = max_subarray_kadane(a, n);
    printf("Maximum subarray sum: %d\n", ans);
    return 0;
}
