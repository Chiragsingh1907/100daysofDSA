#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the index of a value in the inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to construct the tree
struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Pick current node from Preorder traversal using preIndex
    struct Node* tNode = newNode(preorder[(*preIndex)++]);

    // If this node has no children, return
    if (inStart == inEnd) {
        return tNode;
    }

    // Find the index of this node in Inorder traversal
    int inIndex = search(inorder, inStart, inEnd, tNode->data);

    // Using index in Inorder traversal, construct left and right subtrees
    // Elements to the left of inIndex form the left subtree
    tNode->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    // Elements to the right of inIndex form the right subtree
    tNode->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// Function to print postorder traversal
void printPostorder(struct Node* node) {
    if (node == NULL) return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printPostorder(root);
    printf("\n");

    return 0;
}