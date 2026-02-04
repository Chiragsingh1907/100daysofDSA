/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int array[n];
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]);
    }
    int k, comparisons = 0;
    scanf("%d",&k);
    for (int j=0 ; j<n ; j++) {
        if (array[j] == k) {
            printf("Found at index %d\n",j);
        } comparisons +=1 ;
    }
    printf("Comparisons = %d",comparisons);
    return 0;
}