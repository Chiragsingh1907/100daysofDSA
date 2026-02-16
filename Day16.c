#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array to bring duplicates together
    qsort(arr, n, sizeof(int), compare);

    // Count frequencies in the sorted array
    for (int i = 0; i < n; i++) {
        int count = 1;
        // While the next element is the same, increment count
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        printf("%d:%d ", arr[i], count);
    }

    free(arr);
    return 0;
}