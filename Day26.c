#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create and append a node to the Doubly Linked List
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // If the Linked List is empty, make the new node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;

    // Make last node as previous of new node
    new_node->prev = last;
}

// Function to print the list in forward order
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val;

    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Build the list
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            append(&head, val);
        }
    }

    // Traverse and print
    printList(head);

    return 0;
}