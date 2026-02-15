#include <stdio.h>

int main() {
    int m, n;
    
    // Step 1: Input dimensions
    if (scanf("%d %d", &m, &n) != 2) return 1;

    int matrix[m][n];
    long long sum = 0; // Using long long to prevent overflow with large values

    // Step 2: Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step 3: Calculate primary diagonal sum
    // We only need one loop since row index == column index
    int limit = (m < n) ? m : n; 
    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    // Step 4: Output result
    printf("%lld\n", sum);

    return 0;
}