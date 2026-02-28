#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to get the length of the list
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection point
void findIntersection(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move the pointer of the longer list ahead by 'd' nodes
    if (c1 > c2) {
        d = c1 - c2;
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        d = c2 - c1;
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    // Traverse both lists simultaneously
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) { // Comparing values as per your example
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // Input for first list
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head1) head1 = tail1 = temp;
        else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    // Input for second list
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head2) head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    findIntersection(head1, head2);

    return 0;
}