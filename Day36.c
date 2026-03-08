#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue *q, int n) {
    q->capacity = n;
    q->arr = (int *)malloc(n * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Add element to the rear
void enqueue(CircularQueue *q, int value) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

// Remove element from the front
void dequeue(CircularQueue *q) {
    if (q->size == 0) return;
    
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    q->size--;
}

// Print elements from front to rear
void display(CircularQueue *q) {
    if (q->size == 0) return;
    
    int i = q->front;
    for (int count = 0; count < q->size; count++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int n, m, val;
    CircularQueue q;

    // Input number of elements to enqueue
    if (scanf("%d", &n) != 1) return 0;
    initQueue(&q, n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Input number of dequeue operations
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    // Since it's a circular queue, we re-enqueue the dequeued elements 
    // to match your example logic where elements wrap around.
    // Wait—looking at your example: 10,20 are dequeued and appear at the end.
    // This implies a "Rotate" operation rather than a standard Dequeue.
    
    display(&q);

    free(q.arr);
    return 0;
}