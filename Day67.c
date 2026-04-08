#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for Adjacency List
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (Directed)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Recursive DFS helper
void topologicalSortUtil(int v, bool visited[], int stack[], int* top, struct Graph* graph) {
    visited[v] = true;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int connectedVertex = temp->dest;
        if (!visited[connectedVertex]) {
            topologicalSortUtil(connectedVertex, visited, stack, top, graph);
        }
        temp = temp->next;
    }

    // Push current vertex to stack
    stack[(*top)++] = v;
}

// Main function to perform Topological Sort
void topologicalSort(struct Graph* graph) {
    int* stack = malloc(graph->numVertices * sizeof(int));
    int top = 0;
    bool* visited = malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;

    // Call recursive helper for every vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack, &top, graph);
        }
    }

    // Print stack in reverse order
    printf("Topological Ordering: ");
    while (top > 0) {
        printf("%d ", stack[--top]);
    }
    printf("\n");

    free(stack);
    free(visited);
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}