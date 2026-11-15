#include <stdio.h>
#define INF 999999

int min_dist(int dist[], int vis[], int n) {
    int min = INF, idx = -1;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && dist[v] <= min) {
            min = dist[v];
            idx = v;
        }
    }
    return idx;
}

// dijkstra shortest path algorithm
void dijkstra(int g[20][20], int n, int src) {
    int dist[20], vis[20] = {0};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (int c = 0; c < n - 1; c++) {
        int u = min_dist(dist, vis, n);
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && g[u][v] && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    printf("Vertex \tDistance from Source %d\n", src);
    for (int i = 0; i < n; i++) printf("%d \t%d\n", i, dist[i]);
}

int main() {
    int n, src, g[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(g, n, src);
    return 0;
}
