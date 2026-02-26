#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences of a key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Helper function to append nodes to the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int main() {
    struct Node* head = NULL;
    int n, val, key;

    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Build the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    // Read the key to count
    scanf("%d", &key);

    // Count and print result
    printf("%d\n", countOccurrences(head, key));

    return 0;
}