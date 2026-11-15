#include <stdio.h>

// bucket sort for integers
void bucket_sort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];

    int b[10][100], count[10] = {0};
    // distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (a[i] * 10) / (max + 1);
        b[idx][count[idx]++] = a[i];
    }

    // sort individual buckets and merge
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int p = 0; p < count[i]; p++) {
            for (int q = p + 1; q < count[i]; q++) {
                if (b[i][p] > b[i][q]) {
                    int t = b[i][p];
                    b[i][p] = b[i][q];
                    b[i][q] = t;
                }
            }
            a[k++] = b[i][p];
        }
    }
}

int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter non-negative elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    bucket_sort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
