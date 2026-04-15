#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparison function for qsort to sort strings lexicographically
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for n strings
    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = (char *)malloc(100 * sizeof(char)); // Assuming max name length 100
        scanf("%s", votes[i]);
    }

    // Step 1: Sort the names
    qsort(votes, n, sizeof(char *), compareStrings);

    // Step 2: Iterate and count
    char *winner = votes[0];
    int max_votes = 0;
    
    int current_votes = 1;
    for (int i = 1; i <= n; i++) {
        // Check if current name is same as previous or we reached the end
        if (i < n && strcmp(votes[i], votes[i-1]) == 0) {
            current_votes++;
        } else {
            // We found a new name or end of array, check if previous name wins
            if (current_votes > max_votes) {
                max_votes = current_votes;
                winner = votes[i-1];
            }
            current_votes = 1; // Reset for the next candidate
        }
    }

    // Step 3: Output result
    printf("%s %d\n", winner, max_votes);

    // Cleanup
    for (int i = 0; i < n; i++) free(votes[i]);
    free(votes);

    return 0;
}