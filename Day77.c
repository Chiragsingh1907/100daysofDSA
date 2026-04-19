#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000

int adj[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int n, m;

// Standard DFS traversal
void dfs(int node) {
    visited[node] = true;
    for (int i = 1; i <= n; i++) {
        // If there is an edge and the neighbor hasn't been visited
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // Read n (nodes) and m (edges)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        for (int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges and populate the matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u <= n && v <= n) {
            adj[u][v] = 1;
            adj[v][u] = 1; // Undirected graph
        }
    }

    // Edge case: empty graph
    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    // Start DFS from the first node
    dfs(1);

    // Verify if all nodes were reached
    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}