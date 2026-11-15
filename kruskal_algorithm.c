#include <stdio.h>

struct Edge {
    int u, v, w;
};

int find_parent(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = find_parent(parent, parent[i]);
}

void union_sets(int parent[], int u, int v) {
    int root_u = find_parent(parent, u);
    int root_v = find_parent(parent, v);
    parent[root_u] = root_v;
}

// kruskal minimum spanning tree
void kruskal_mst(struct Edge edges[], int n, int e) {
    // sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge t = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = t;
            }
        }
    }

    int parent[20];
    for (int i = 0; i < n; i++) parent[i] = i;

    int total = 0, count = 0;
    printf("MST Edges:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int r1 = find_parent(parent, edges[i].u);
        int r2 = find_parent(parent, edges[i].v);
        if (r1 != r2) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            union_sets(parent, r1, r2);
            count++;
        }
    }
    printf("Total MST weight: %d\n", total);
}

int main() {
    int n, e;
    struct Edge edges[100];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal_mst(edges, n, e);
    return 0;
}
