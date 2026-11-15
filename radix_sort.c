#include <stdio.h>

int get_max(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    return mx;
}

// count sort for current digit
void count_sort(int a[], int n, int exp) {
    int out[100], count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        out[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) a[i] = out[i];
}

// radix sort digits
void radix_sort(int a[], int n) {
    int m = get_max(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10) count_sort(a, n, exp);
}

int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    radix_sort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
