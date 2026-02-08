#include <stdio.h>

// Recursive function to calculate a^b
long long power(int a, int b) {
    // Base case: any number to the power of 0 is 1
    if (b == 0) {
        return 1;
    }
    // If power is negative, we'd need double, but 
    // for integer problems, we assume b >= 0
    if (b < 0) {
        return 0; // Or handle as 1/power(a, -b) if using floats
    }
    
    // Recursive step: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    
    // Taking input
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }
    
    // Output the result
    printf("%lld\n", power(a, b));
    
    return 0;
}