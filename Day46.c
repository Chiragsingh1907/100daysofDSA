#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Level Order Traversal Function
void printLevelOrder(struct Node* root, int n) {
    if (root == NULL) return;

    // Create a queue using an array of Node pointers
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;

    // Enqueue root
    queue[rear++] = root;

    while (front < rear) {
        struct Node* tempNode = queue[front++];

        printf("%d ", tempNode->data);

        // Enqueue left child
        if (tempNode->left != NULL) {
            queue[rear++] = tempNode->left;
        }

        // Enqueue right child
        if (tempNode->right != NULL) {
            queue[rear++] = tempNode->right;
        }
    }
    free(queue);
}

// Function to build tree from level-order array input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* current = queue[front++];
        
        // Left
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }
        // Right
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    printLevelOrder(root, n);
    printf("\n");

    free(arr);
    return 0;
}