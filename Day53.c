#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue item to store node and its horizontal distance
struct QueueItem {
    struct Node* node;
    int hd;
};

// Linked list node to store data for each vertical line
struct List {
    int data;
    struct List* next;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Global array of linked lists to store nodes at each horizontal distance
// Using 500 as offset so HD 0 is at index 500
struct List* columns[1001];
int min_hd = 0, max_hd = 0;

void addToList(int hd, int data) {
    int idx = hd + 500;
    struct List* temp = (struct List*)malloc(sizeof(struct List));
    temp->data = data;
    temp->next = NULL;

    if (columns[idx] == NULL) {
        columns[idx] = temp;
    } else {
        struct List* curr = columns[idx];
        while (curr->next) curr = curr->next;
        curr->next = temp;
    }
    if (hd < min_hd) min_hd = hd;
    if (hd > max_hd) max_hd = hd;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QueueItem queue[MAX_NODES];
    int head = 0, tail = 0;

    queue[tail++] = (struct QueueItem){root, 0};

    while (head < tail) {
        struct QueueItem curr = queue[head++];
        struct Node* temp = curr.node;
        int hd = curr.hd;

        addToList(hd, temp->data);

        if (temp->left) queue[tail++] = (struct QueueItem){temp->left, hd - 1};
        if (temp->right) queue[tail++] = (struct QueueItem){temp->right, hd + 1};
    }
}

// Helper function to build tree from level order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[MAX_NODES];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        curr->left = newNode(arr[i++]);
        if (curr->left) queue[tail++] = curr->left;
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    
    for(int i=0; i<1001; i++) columns[i] = NULL;

    verticalOrder(root);

    for (int i = min_hd; i <= max_hd; i++) {
        struct List* curr = columns[i + 500];
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }

    return 0;
}