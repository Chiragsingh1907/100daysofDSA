#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    if (n < 2) return;

    // Sort the array: O(n log n)
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int element1, element2;

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if this sum is closer to zero than the current min_sum
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            element1 = arr[left];
            element2 = arr[right];
        }

        // Move pointers based on the sum
        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // If sum is exactly 0, it doesn't get closer than this
            break;
        }
    }

    printf("%d %d\n", element1, element2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findClosestToZero(arr, n);

    free(arr);
    return 0;
}