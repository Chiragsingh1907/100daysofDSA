#include <stdio.h>
#include <string.h>

int main() {
    char code[100]; // Buffer to store the input
    
    // Read input (assuming no spaces as per problem)
    if (scanf("%s", code) != 1) return 0;

    int len = strlen(code);
    
    // Mirror operation: Swap characters from both ends
    for (int i = 0; i < len / 2; i++) {
        char temp = code[i];
        code[i] = code[len - 1 - i];
        code[len - 1 - i] = temp;
    }

    // Output the mirrored code name
    printf("%s\n", code);

    return 0;
}