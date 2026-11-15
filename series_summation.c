#include <stdio.h>
#include <math.h>

// naive O(n^2) method
double series_naive(double x, int n) {
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        double p = 1;
        for (int j = 0; j < i; j++) p *= x;
        sum += p;
    }
    return sum;
}

// horner rule O(n) method
double series_horner(double x, int n) {
    double sum = 1;
    for (int i = n; i >= 1; i--) sum = 1 + x * sum;
    return sum;
}

int main() {
    double x;
    int n;
    printf("Enter value of x: ");
    scanf("%lf", &x);
    printf("Enter number of terms n: ");
    scanf("%d", &n);

    printf("Sum using O(n^2): %.4lf\n", series_naive(x, n));
    printf("Sum using O(n): %.4lf\n", series_horner(x, n));
    return 0;
}
