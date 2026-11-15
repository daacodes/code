#include <stdio.h>

// cycle detection in undirected graph
int dfs_undirected(int u, int p, int adj[20][20], int vis[], int n) {
    vis[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!vis[v]) {
                if (dfs_undirected(v, u, adj, vis, n)) return 1;
            } else if (v != p) return 1;
        }
    }
    return 0;
}

// cycle detection in directed graph
int dfs_directed(int u, int adj[20][20], int vis[], int rec[], int n) {
    vis[u] = 1;
    rec[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!vis[v] && dfs_directed(v, adj, vis, rec, n)) return 1;
            else if (rec[v]) return 1;
        }
    }
    rec[u] = 0;
    return 0;
}

int main() {
    int choice, n, adj[20][20];
    printf("Choose graph type (1: Undirected, 2: Directed): ");
    scanf("%d", &choice);
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &adj[i][j]);
    }

    int has_cycle = 0;
    if (choice == 1) {
        int vis[20] = {0};
        for (int i = 0; i < n; i++) {
            if (!vis[i] && dfs_undirected(i, -1, adj, vis, n)) {
                has_cycle = 1;
                break;
            }
        }
    } else {
        int vis[20] = {0}, rec[20] = {0};
        for (int i = 0; i < n; i++) {
            if (!vis[i] && dfs_directed(i, adj, vis, rec, n)) {
                has_cycle = 1;
                break;
            }
        }
    }

    if (has_cycle) printf("Cycle detected in graph\n");
    else printf("No cycle found\n");
    return 0;
}
