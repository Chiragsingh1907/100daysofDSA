#include <stdio.h>

int main() {
    int p, q;

    // Input for Server Log 1
    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Input for Server Log 2
    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // The merged log size will be p + q
    int merged[p + q];
    int i = 0, j = 0, k = 0;

    // Compare elements from both arrays
    // Use pointers i (for log1) and j (for log2)
    
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k] = log1[i];
            i++;
        } else {
            merged[k] = log2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of log1, if any (log2 finished first)
    while (i < p) {
        merged[k] = log1[i];
        i++;
        k++;
    }

    // Copy remaining elements of log2, if any (log1 finished first)
    while (j < q) {
        merged[k] = log2[j];
        j++;
        k++;
    }

    // Print the final chronological log
    for (int m = 0; m < p + q; m++) {
        printf("%d%s", merged[m], (m == p + q - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}