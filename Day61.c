#include <stdio.h>

#define MAX 100

void buildAdjacencyMatrix() {
    int n, m, i, j;
    int u, v;
    int isDirected;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    // 1. Initialize matrix with zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // 2. Input edges and populate matrix
    printf("Enter %d pairs of edges (u v):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        // Assuming 0-indexed vertices. 
        // If input is 1-indexed, use adj[u-1][v-1]
        adj[u][v] = 1;

        if (!isDirected) {
            adj[v][u] = 1; // Symmetric entry for undirected graphs
        }
    }

    // 3. Output the resulting matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    buildAdjacencyMatrix();
    return 0;
}