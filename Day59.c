#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Global map to store indices of inorder elements for O(1) lookup
unordered_map<int, int> mp;

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int& postIdx, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    // Pick current node from postorder and decrement postIdx
    int curr = postorder[postIdx--];
    Node* node = new Node(curr);

    if (inStart == inEnd) return node;

    // Find position of this node in inorder traversal
    int pos = mp[curr];

    // Build right subtree first (because postorder is L-R-Root)
    node->right = buildTree(inorder, postorder, postIdx, pos + 1, inEnd);
    node->left = buildTree(inorder, postorder, postIdx, inStart, pos - 1);

    return node;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    // Map inorder values to their indices
    for (int i = 0; i < n; i++) mp[inorder[i]] = i;

    int postIdx = n - 1;
    Node* root = buildTree(inorder, postorder, postIdx, 0, n - 1);

    preorder(root);
    cout << endl;

    return 0;
}