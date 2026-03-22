#include <stddef.h> // For NULL

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Traverse until we hit an empty node or find our target
    while (root != NULL && root->val != val) {
        if (val < root->val) {
            // Target is smaller, go to the left subtree
            root = root->left;
        } else {
            // Target is larger, go to the right subtree
            root = root->right;
        }
    }
    
    // Will return the matching node, or NULL if it wasn't found
    return root; 
}