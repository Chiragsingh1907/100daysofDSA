#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    // Read table size and number of operations
    if (scanf("%d %d", &m, &q) != 2) return 0;

    int *hashTable = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            for (int j = 0; j < m; j++) {
                int index = (key % m + j * j) % m;
                if (hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    break;
                }
            }
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for (int j = 0; j < m; j++) {
                int index = (key % m + j * j) % m;
                if (hashTable[index] == key) {
                    found = 1;
                    break;
                } else if (hashTable[index] == EMPTY) {
                    // Optimization: if we hit an empty slot, 
                    // the key was never inserted.
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(hashTable);
    return 0;
}