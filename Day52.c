#include <stdio.h>
#include <stdlib.h>

// Standard tree node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;
    
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        
        // Left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        
        // Right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    return root;
}

// Core LCA Function
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If node matches either n1 or n2, this is a potential ancestor
    if (root->data == n1 || root->data == n2) return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    // If both are non-NULL, current node is the LCA
    if (leftLCA && rightLCA) return root;

    // Otherwise return the non-NULL child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca) printf("%d\n", lca->data);
    
    return 0;
}