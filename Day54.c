#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Simple Stack implementation for Nodes
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

int isEmpty(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Zigzag Traversal using two stacks
void printZigZag(struct Node* root, int n) {
    if (root == NULL) return;

    struct Stack* s1 = createStack(n); // Left to Right
    struct Stack* s2 = createStack(n); // Right to Left

    push(s1, root);

    while (!isEmpty(s1) || !isEmpty(s2)) {
        // Process Level: Left to Right
        while (!isEmpty(s1)) {
            struct Node* temp = pop(s1);
            printf("%d ", temp->data);

            // Push children to s2: Left then Right
            if (temp->left) push(s2, temp->left);
            if (temp->right) push(s2, temp->right);
        }

        // Process Level: Right to Left
        while (!isEmpty(s2)) {
            struct Node* temp = pop(s2);
            printf("%d ", temp->data);

            // Push children to s1: Right then Left
            if (temp->right) push(s1, temp->right);
            if (temp->left) push(s1, temp->left);
        }
    }
}

// Helper to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[tail++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[tail++] = curr->right;
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printZigZag(root, n);

    return 0;
}