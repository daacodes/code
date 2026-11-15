#include <stdio.h>
#include <math.h>

// move disk between pegs
void move_disk(char s, char d, int disk) {
    printf("Move disk %d from %c to %c\n", disk, s, d);
}

// iterative tower of hanoi
void hanoi_non_recursive(int n, char src, char aux, char dest) {
    int total_moves = pow(2, n) - 1;
    char s = src, a = aux, d = dest;

    if (n % 2 == 0) {
        char t = d;
        d = a;
        a = t;
    }

    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) printf("Move between %c and %c\n", s, d);
        else if (i % 3 == 2) printf("Move between %c and %c\n", s, a);
        else if (i % 3 == 0) printf("Move between %c and %d\n", a, d);
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Steps for Tower of Hanoi:\n");
    hanoi_non_recursive(n, 'A', 'B', 'C');
    return 0;
}
