#include <stdio.h>

// Lower Bound: First index where arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            high = mid; // Look on the left side to find the first occurrence
        } else {
            low = mid + 1; // Look on the right side
        }
    }
    return low;
}

// Upper Bound: First index where arr[i] > x
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            high = mid; // Look on the left side
        } else {
            low = mid + 1; // Look on the right side
        }
    }
    return low;
}

int main() {
    int n, x;

    // Input size
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target value
    if (scanf("%d", &x) != 1) return 0;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}