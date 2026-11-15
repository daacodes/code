#include <stdio.h>

// topological sort using indegree
void topological_sort(int adj[20][20], int n) {
    int in_deg[20] = {0}, q[20], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) in_deg[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) q[rear++] = i;
    }

    int count = 0, topo[20];
    while (front < rear) {
        int u = q[front++];
        topo[count++] = u;
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                in_deg[v]--;
                if (in_deg[v] == 0) q[rear++] = v;
            }
        }
    }

    if (count < n) {
        printf("Graph has a cycle, topological sort not possible.\n");
        return;
    }

    printf("Topological Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", topo[i]);
    printf("\n");
}

int main() {
    int n, adj[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter directed adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &adj[i][j]);
    }

    topological_sort(adj, n);
    return 0;
}
