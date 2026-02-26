#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete the first occurrence of a key
void deleteKey(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    // Case 1: If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);            
        return;
    }

    // Case 2: Search for the key, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: Key was not present in the list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Helper function to append nodes
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, val, key;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    scanf("%d", &key);

    deleteKey(&head, key);
    printList(head);

    return 0;
}