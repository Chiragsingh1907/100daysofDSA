#include <stdio.h>
#include <stdlib.h>

// A simple structure for Hash Table entries
typedef struct {
    int sum;
    int index;
} HashEntry;

// Function to find the longest subarray with 0 sum
int maxLen(int arr[], int n) {
    // Hash table to store (prefix_sum, first_occurrence_index)
    // Using a size larger than n to reduce collisions
    int tableSize = n * 2;
    HashEntry* hashTable = (HashEntry*)malloc(tableSize * sizeof(HashEntry));
    
    // Initialize hash table with a value representing "empty"
    for (int i = 0; i < tableSize; i++) {
        hashTable[i].sum = -1e9; // Sentinel value
    }

    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            max_len = i + 1;
        } else {
            // Check if sum exists in hash table
            int h = abs(sum) % tableSize;
            while (hashTable[h].sum != -1e9) {
                if (hashTable[h].sum == sum) {
                    int len = i - hashTable[h].index;
                    if (len > max_len) max_len = len;
                    break;
                }
                h = (h + 1) % tableSize; // Linear probing
            }

            // If not found, insert current sum and index
            if (hashTable[h].sum == -1e9) {
                hashTable[h].sum = sum;
                hashTable[h].index = i;
            }
        }
    }

    free(hashTable);
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}