#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int count[26] = {0}; // Frequency array for 'a'-'z'
    int n = strlen(s);

    // Step 1: Build the frequency map
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Step 2: Find the first char with count 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // Step 3: Return '$' if no unique character exists
    return '$';
}

int main() {
    char s[100001]; // Assuming a reasonable max length
    if (scanf("%s", s) == 1) {
        printf("%c\n", firstNonRepeating(s));
    }
    return 0;
}