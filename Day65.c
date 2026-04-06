#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    struct Node* head[MAX_NODES];
};

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->head[src];
    graph->head[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

// DFS Utility to detect cycle
bool isCycleUtil(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    struct Node* temp = graph->head[v];
    while (temp != NULL) {
        int neighbor = temp->dest;

        // If neighbor is not visited, recurse
        if (!visited[neighbor]) {
            if (isCycleUtil(graph, neighbor, visited, v))
                return true;
        }
        // If visited and not the parent, there's a cycle
        else if (neighbor != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Main function to check for cycles in the whole graph
void detectCycle(struct Graph* graph, int numVertices) {
    bool visited[MAX_NODES] = {false};

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (isCycleUtil(graph, i, visited, -1)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    int vertices = 5;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < vertices; i++) graph->head[i] = NULL;

    // Example: 0-1, 1-2, 2-0 (Cycle)
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 4);

    detectCycle(graph, vertices);

    return 0;
}