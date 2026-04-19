#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1000
#define INF INT_MAX

int graph[MAX][MAX];
int key[MAX];
bool inMST[MAX];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize the graph with Infinity
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        inMST[i] = false;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Handle multiple edges between same nodes by picking the minimum weight
        if (w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int total_weight = 0;
    key[1] = 0; // Start from node 1

    for (int count = 0; count < n; count++) {
        // Step 1: Pick the minimum key vertex not yet in MST
        int min = INF, u = -1;

        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // If the graph is disconnected and we can't find a vertex
        if (u == -1) break;

        // Step 2: Add the vertex to the MST
        inMST[u] = true;
        total_weight += key[u];

        // Step 3: Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);

    return 0;
}