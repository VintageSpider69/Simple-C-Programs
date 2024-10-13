// program to add polynomials using linked lists
#include <stdio.h>
#include <stdlib.h>

// Structure for a term of the polynomial
struct Term {
    int coeff;
    int exp;
    struct Term* next;
};


struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}


void insertTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff; // Combine like terms
            free(newTerm);
        } else {
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    // Traverse the first polynomial and insert terms
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // Traverse the second polynomial and insert terms
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    // Combine like terms in the result polynomial
    struct Term* combined = NULL;
    struct Term* current = result;

    while (current != NULL) {
        // Check if the term already exists in the combined polynomial
        struct Term* temp = combined;
        int coeff = current->coeff;
        int exp = current->exp;

        while (temp != NULL) {
            if (temp->exp == exp) {
                coeff += temp->coeff; // Combine coefficients
                break;
            }
            temp = temp->next;
        }

        // Insert the term only if it doesn't exist
        if (temp == NULL) {
            insertTerm(&combined, coeff, exp);
        } else {
            // If the term exists, update the coefficient of the existing term
            struct Term* existing = combined;
            while (existing != NULL) {
                if (existing->exp == exp) {
                    existing->coeff = coeff;
                    break;
                }
                existing = existing->next;
            }
        }

        current = current->next;
    }

    // Free the original result polynomial
    current = result;
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }

    return combined;
}

// Function to print the polynomial
void printPolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to read a polynomial from user input
struct Term* readPolynomial() {
    struct Term* poly = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    int i; // Declare i here
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    return poly;
}

// Main function
int main() {
    printf("Input first polynomial:\n");
    struct Term* poly1 = readPolynomial();

    printf("Input second polynomial:\n");
    struct Term* poly2 = readPolynomial();

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    printPolynomial(result);

    return 0;
}
