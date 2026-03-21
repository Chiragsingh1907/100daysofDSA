#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 2. Helper function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 3. Recursive function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    // Base Case: If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    // Return the (unchanged) node pointer
    return root;
}

// 4. Utility function for inorder traversal (Left, Root, Right)
// An inorder traversal of a BST always prints elements in sorted order.
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to test the implementation
int main() {
    struct Node* root = NULL;

    /* Let's create the following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
    */
    
    // Inserting nodes
    root = insert(root, 50); // First node becomes the root
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print inorder traversal to verify standard BST properties
    printf("Inorder traversal of the constructed BST: \n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}