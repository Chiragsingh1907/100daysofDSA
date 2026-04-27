#include <stdio.h>

int mySqrt(int n) {
    // Handle base cases for 0 and 1
    if (n < 2) {
        return n;
    }

    int left = 1, right = n / 2;
    int ans = 0;

    while (left <= right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Use long long to prevent overflow during squaring
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid; // Exact square root found
        } else if (square < n) {
            ans = mid;     // mid is a candidate, but there might be a larger one
            left = mid + 1;
        } else {
            right = mid - 1; // Square is too big, search lower half
        }
    }

    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", mySqrt(n));
    }
    return 0;
}