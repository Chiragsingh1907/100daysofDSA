#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the list
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        // Read value and allocate memory for new node
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // If list is empty, set head and tail to new node
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, link the new node to the end and update tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Output the list
    traverseList(head);

    // Free memory (Good practice in C)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}