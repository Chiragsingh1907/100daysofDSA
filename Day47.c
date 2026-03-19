#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the height of the binary tree
int getHeight(struct Node* node) {
    // Base case: empty tree has height -1
    if (node == NULL) {
        return -1;
    }

    // Recursive calls for subtrees
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // Return the maximum of the two plus 1 for the current node
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    /* Constructing a sample tree:
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

    printf("Height of the tree is: %d\n", getHeight(root));

    return 0;
}