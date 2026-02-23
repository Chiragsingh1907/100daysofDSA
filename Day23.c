#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; // Temporary node to start the list
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining elements of the non-empty list
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

// Helper function to build a list from user input
struct Node* buildList(int count) {
    if (count <= 0) return NULL;
    struct Node *head = NULL, *temp = NULL;
    for (int i = 0; i < count; i++) {
        int val;
        scanf("%d", &val);
        if (head == NULL) {
            head = createNode(val);
            temp = head;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }
    return head;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, m;

    // Input for first list
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);

    // Input for second list
    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    // Merge and print
    struct Node* mergedHead = mergeLists(list1, list2);
    printList(mergedHead);

    return 0;
}