#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node (maintaining descending order of exponents)
void insert(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    
    // If list is empty or new exponent is the highest
    if (*poly == NULL || exp > (*poly)->exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display the polynomial
void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = poly;
    while (temp != NULL) {
        // Handle coefficient and x
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Handle the " + " connector
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, coeff, exp;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&poly, coeff, exp);
    }

    display(poly);

    return 0;
}