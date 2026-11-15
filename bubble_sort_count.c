#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, a[1000], cmp = 0;
    printf("Enter number of random integers: ");
    scanf("%d", &n);

    // generate random array
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = rand() % 100;

    printf("Original array:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    // bubble sort with comparison count
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cmp++;
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("Total comparisons: %d\n", cmp);

    return 0;
}
