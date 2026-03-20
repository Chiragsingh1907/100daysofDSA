#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* node) {
    // Base case: empty tree
    if (node == NULL) {
        return 0;
    }
    
    // Check if the current node is a leaf node
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    
    // Recur for left and right subtrees and sum them up
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int main() {
    /* Example Tree:
                1
               / \
              2   3
             / \
            4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Number of leaf nodes in the tree: %d\n", countLeafNodes(root));

    return 0;
}