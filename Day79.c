#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an adjacency list node
struct Node {
    int target, weight;
    struct Node* next;
};

// Structure to represent the Min-Heap node
struct HeapNode {
    int v, dist;
};

// Structure to represent a Min-Heap
struct MinHeap {
    int size;
    int capacity;
    int* pos; // To track positions of vertices in heap
    struct HeapNode** array;
};

// Function to create a new adjacency list node
struct Node* newNode(int target, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->target = target;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Standard Min-Heapify function
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = minHeap->array[smallest];
        struct HeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        struct HeapNode* temp = minHeap->array[smallest];
        minHeap->array[smallest] = minHeap->array[idx];
        minHeap->array[idx] = temp;

        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;

    struct HeapNode* root = minHeap->array[0];
    struct HeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        
        struct HeapNode* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void dijkstra(int n, int source, struct Node** adj) {
    int dist[n + 1];
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc((n + 1) * sizeof(int));
    minHeap->size = n;
    minHeap->capacity = n;
    minHeap->array = (struct HeapNode**)malloc(n * sizeof(struct HeapNode*));

    for (int v = 1; v <= n; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v - 1] = (struct HeapNode*)malloc(sizeof(struct HeapNode));
        minHeap->array[v - 1]->v = v;
        minHeap->array[v - 1]->dist = dist[v];
        minHeap->pos[v] = v - 1;
    }

    dist[source] = 0;
    decreaseKey(minHeap, source, dist[source]);

    while (minHeap->size != 0) {
        struct HeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            if (minHeap->pos[v] < minHeap->size && dist[u] != INT_MAX && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        struct Node* node = newNode(v, w);
        node->next = adj[u];
        adj[u] = node;
    }

    int source;
    scanf("%d", &source);
    dijkstra(n, source, adj);

    return 0;
}