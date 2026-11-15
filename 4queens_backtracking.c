#include <stdio.h>
#include <stdlib.h>

int board[4][4];

// check queen safety
int is_safe(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i][c]) return 0;
    }
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return 0;
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < 4; i--, j++) {
        if (board[i][j]) return 0;
    }
    return 1;
}

// solve 4-queens using backtracking
int solve_nqueens(int r) {
    if (r >= 4) return 1;
    for (int c = 0; c < 4; c++) {
        if (is_safe(r, c)) {
            board[r][c] = 1;
            if (solve_nqueens(r + 1)) return 1;
            board[r][c] = 0;
        }
    }
    return 0;
}

int main() {
    int start;
    printf("Enter 1 to solve 4-Queens problem: ");
    scanf("%d", &start);

    if (solve_nqueens(0)) {
        printf("Arrangement for 4-Queens:\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j]) printf("Q ");
                else printf(". ");
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}
