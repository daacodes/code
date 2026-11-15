#include <stdio.h>

// dfs to detect undirected cycle
int dfs_cycle(int u, int p, int adj[20][20], int vis[], int n) {
    vis[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!vis[v]) {
                if (dfs_cycle(v, u, adj, vis, n)) return 1;
            } else if (v != p) return 1;
        }
    }
    return 0;
}

int main() {
    int n, adj[20][20], vis[20] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter undirected adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &adj[i][j]);
    }

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs_cycle(i, -1, adj, vis, n)) {
            found = 1;
            break;
        }
    }

    if (found) printf("Graph contains cycle\n");
    else printf("No cycle in graph\n");
    return 0;
}
