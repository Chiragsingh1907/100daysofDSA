#include <stdio.h>

int main() {
    int n;

    // Get the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1; // Basic error handling for invalid size
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element
    int max = arr[0];
    int min = arr[0];

    // Single pass through the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Output the results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}