#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation: Add an element to the end
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation: Remove an element from the front
void dequeue(struct Queue* q) {
    // If queue is empty
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = q->front;
    printf("%d\n", temp->data);

    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int main() {
    struct Queue* q = createQueue();
    int n, choice, value;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);
        if (choice == 1) { // Assuming 1 for Enqueue
            scanf("%d", &value);
            enqueue(q, value);
        } else if (choice == 2) { // Assuming 2 for Dequeue
            dequeue(q);
        }
    }

    return 0;
}