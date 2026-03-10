#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Deque structure
typedef struct {
    Node *front;
    Node *rear;
    int size;
} Deque;

// Initialize Deque
void initDeque(Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// O(1) Push Front
void push_front(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL)
        dq->rear = newNode;
    else
        dq->front->prev = newNode;

    dq->front = newNode;
    dq->size++;
}

// O(1) Push Back
void push_back(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL)
        dq->front = newNode;
    else
        dq->rear->next = newNode;

    dq->rear = newNode;
    dq->size++;
}

// O(1) Pop Front
void pop_front(Deque *dq) {
    if (dq->front == NULL) return;
    Node *temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;

    free(temp);
    dq->size--;
}

// O(1) Pop Back
void pop_back(Deque *dq) {
    if (dq->rear == NULL) return;
    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;

    free(temp);
    dq->size--;
}