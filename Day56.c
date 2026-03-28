#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to check if two trees are mirror images
bool isMirror(struct Node* tree1, struct Node* tree2) {
    // If both are NULL, they are mirrors
    if (tree1 == NULL && tree2 == NULL) {
        return true;
    }
    // If only one is NULL, they are not mirrors
    if (tree1 == NULL || tree2 == NULL) {
        return false;
    }
    // Check if the current nodes match, and recursively check their children
    return (tree1->data == tree2->data) &&
           isMirror(tree1->left, tree2->right) &&
           isMirror(tree1->right, tree2->left);
}

// Function to check if a tree is symmetric
bool isSymmetric(struct Node* root) {
    if (root == NULL) {
        return true; // An empty tree is symmetric
    }
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("YES\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: empty root
    if (arr[0] == -1) {
        printf("YES\n");
        free(arr);
        return 0;
    }

    // Build the tree using a queue
    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (front < rear && i < n) {
        struct Node* current = queue[front++];

        // Assign left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Assign right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    // Output the result
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Memory cleanup (Queue and Array)
    free(queue);
    free(arr);
    
    return 0;
}