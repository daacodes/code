#include <stdio.h>
#define INF 999999

// all pairs shortest path
void floyd_warshall(int dist[20][20], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between all pairs:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF / 2) printf("INF\t");
            else printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, dist[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weight matrix (enter 999999 if no direct edge, 0 for diagonal):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &dist[i][j]);
    }

    floyd_warshall(dist, n);
    return 0;
}
