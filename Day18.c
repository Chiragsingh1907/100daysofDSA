#include <stdio.h>
#include <stdlib.h>

// Helper function to reverse a portion of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    // Read array size
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read rotation steps
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    if (k > 0) {
        // Step 1: Reverse the whole array
        // [1, 2, 3, 4, 5] -> [5, 4, 3, 2, 1]
        reverse(arr, 0, n - 1);

        // Step 2: Reverse the first k elements
        // [5, 4, 3, 2, 1] -> [4, 5, 3, 2, 1]
        reverse(arr, 0, k - 1);

        // Step 3: Reverse the rest
        // [4, 5, 3, 2, 1] -> [4, 5, 1, 2, 3]
        reverse(arr, k, n - 1);
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}