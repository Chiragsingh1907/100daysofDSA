#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[1000];
    
    // Read the input string
    if (scanf("%s", s) != 1) {
        return 0;
    }

    int left = 0;
    int right = strlen(s) - 1;
    bool isPalindrome = true;

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}