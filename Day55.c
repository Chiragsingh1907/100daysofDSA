#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Standard Queue for Tree Construction and BFS
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printRightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000]; // Array-based queue
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head; // Number of nodes at current level

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];

            // If it's the last node of the current level, print it
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0 || arr[0] == -1) return 0;

    // Building the tree from level-order array
    struct Node* root = createNode(arr[0]);
    struct Node* buildQueue[1000];
    int bHead = 0, bTail = 0;
    buildQueue[bTail++] = root;

    int i = 1;
    while (bHead < bTail && i < n) {
        struct Node* curr = buildQueue[bHead++];

        // Left Child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            buildQueue[bTail++] = curr->left;
        }
        i++;

        // Right Child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            buildQueue[bTail++] = curr->right;
        }
        i++;
    }

    printRightView(root);

    return 0;
}