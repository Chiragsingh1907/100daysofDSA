#include <stdio.h>
#include <stdbool.h>

/**
 * Function to check if the array represents a Min-Heap.
 * We only need to iterate up to (N-2)/2 because nodes beyond 
 * that are leaf nodes and have no children to check.
 */
bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Check left child
        if (arr[i] > arr[2 * i + 1]) {
            return false;
        }

        // Check right child (if it exists)
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}