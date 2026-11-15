#include <stdio.h>
#define INF 999999

struct Edge {
    int u, v, w;
};

// bellman ford shortest path
void bellman_ford(struct Edge edges[], int n, int e, int src) {
    int dist[20];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    // relax edges n - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check negative weight cycle
    for (int j = 0; j < e; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex \tDistance from %d\n", src);
    for (int i = 0; i < n; i++) printf("%d \t%d\n", i, dist[i]);
}

int main() {
    int n, e, src;
    struct Edge edges[100];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellman_ford(edges, n, e, src);
    return 0;
}
