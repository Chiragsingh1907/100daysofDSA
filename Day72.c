#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char findFirstRepeated(char* s) {
    // Array to store the presence of characters 'a' through 'z'
    bool visited[26] = {false};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        // If we have seen this character before, it's our answer
        if (visited[index]) {
            return s[i];
        }

        // Mark the character as seen
        visited[index] = true;
    }

    // No repeated character found
    return '\0'; 
}

int main() {
    char s[1000];
    if (scanf("%s", s) == 1) {
        char result = findFirstRepeated(s);
        
        if (result != '\0') {
            printf("%c\n", result);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}