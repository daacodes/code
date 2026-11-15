#include <stdio.h>

// binary search in sorted array
int binary_search(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, a[100];
    printf("Enter number of sorted elements: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos = binary_search(a, n, key);
    if (pos != -1) printf("Found at index %d\n", pos);
    else printf("Not found\n");

    return 0;
}
