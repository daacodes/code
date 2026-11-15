#include <stdio.h>

// traverse component using dfs
void dfs_comp(int u, int adj[20][20], int vis[], int n) {
    vis[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !vis[v]) {
            dfs_comp(v, adj, vis, n);
        }
    }
}

int main() {
    int n, adj[20][20], vis[20] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter undirected adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &adj[i][j]);
    }

    int comp_count = 0;
    printf("Connected Components:\n");
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            comp_count++;
            printf("Component %d: ", comp_count);
            dfs_comp(i, adj, vis, n);
            printf("\n");
        }
    }

    printf("Total connected components: %d\n", comp_count);
    return 0;
}
