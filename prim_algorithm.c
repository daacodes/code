#include <stdio.h>
#define INF 999999

int min_key(int key[], int mst[], int n) {
    int min = INF, min_idx = -1;
    for (int v = 0; v < n; v++) {
        if (!mst[v] && key[v] < min) {
            min = key[v];
            min_idx = v;
        }
    }
    return min_idx;
}

// prim minimum spanning tree
void prim_mst(int cost[20][20], int n) {
    int parent[20], key[20], mst[20] = {0};
    for (int i = 0; i < n; i++) key[i] = INF;
    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {
        int u = min_key(key, mst, n);
        mst[u] = 1;
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !mst[v] && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    int total = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, cost[i][parent[i]]);
        total += cost[i][parent[i]];
    }
    printf("Total MST weight: %d\n", total);
}

int main() {
    int n, cost[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &cost[i][j]);
    }

    prim_mst(cost, n);
    return 0;
}
