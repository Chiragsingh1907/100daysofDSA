#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // A matrix must be square to be symmetric
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int matrix[m][n];

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check for symmetry
    int isSymmetric = 1; // Assume true
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Check if element at [i][j] matches its reflection [j][i]
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}