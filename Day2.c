/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated
*/

#include <stdio.h>

int main() {
    int n; // n= size of array.
    scanf("%d",&n);

    int array[n];  // Declare array of size n.
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]);
    }

    int pos;  // Declare position (1-based) in which element is deleted.
    scanf("%d",&pos);

    for (int i=pos ; i<n ; i++) {  // Left shift the element from (pos-1) to n. to deletee an element.
        array[i-1] = array[i];
    }

    for (int i=0 ; i<n-1 ; i++) { // Prints the new array.
        printf("%d ",array[i]);
    }
    printf("%d",sizeof(array)/sizeof(array[0]));
    return 0;
}