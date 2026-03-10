#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// O(log n) - Restore heap property upwards
void insert(int val) {
    if (size >= MAX) return;
    heap[size] = val;
    int curr = size;
    size++;

    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

// O(log n) - Restore heap property downwards
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;

    int curr = 0;
    while (2 * curr + 1 < size) {
        int smallest = 2 * curr + 1;
        int right = 2 * curr + 2;
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (heap[curr] <= heap[smallest]) break;
        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }
}

void peek() {
    if (size == 0) printf("-1\n");
    else printf("%d\n", heap[0]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[10];
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}