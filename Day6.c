#include <stdio.h>

int main() {
    int n;

    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Always print the first element
    printf("%d", arr[0]);

    // Iterate starting from the second element
    for (int i = 1; i < n; i++) {
        // Only print if the current element is different from the previous one
        if (arr[i] != arr[i - 1]) {
            printf(" %d", arr[i]);
        }
    }

    printf("\n");
    return 0;
}