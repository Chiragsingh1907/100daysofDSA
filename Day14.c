#include <stdio.h>

int main() {
    int n, i, j;
    int isIdentity = 1; // Assume it is identity until proven otherwise

    // Get matrix size
    if (scanf("%d", &n) != 1) return 1;

    int matrix[n][n];

    // Input matrix and check conditions simultaneously
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            // Check diagonal elements
            if (i == j && matrix[i][j] != 1) {
                isIdentity = 0;
            }
            // Check non-diagonal elements
            else if (i != j && matrix[i][j] != 0) {
                isIdentity = 0;
            }
        }
    }

    // Final Output
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}