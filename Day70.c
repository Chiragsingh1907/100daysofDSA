#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a weighted edge
struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, int m, int source, struct Edge edges[]) {
    // Use a long long array for distances to handle potential overflows
    // and initialize with a large value (INF)
    long long dist[n + 1];
    for (int i = 0; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Step 1: Relax all edges (n - 1) times
    for (int i = 1; i <= n - 1; i++) {
        int updated = 0;
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                updated = 1;
            }
        }
        // Optimization: If no distance was updated, we've found the shortest paths
        if (!updated) break;
    }

    // Step 2: Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 3: Print the shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("INF ");
        } else {
            printf("%lld ", dist[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, m, source;

    // Input number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Input source vertex
    scanf("%d", &source);

    bellmanFord(n, m, source, edges);

    free(edges);
    return 0;
}