//  Write a program to perform addition of two polynomial equations using 
// appropriate data structure. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};  
void insertTerm(struct Node** head_ref, int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    if (*head_ref == NULL || (*head_ref)->exp < exp) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node** result) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coeff + poly2->coeff;
            if (sum_coeff != 0) {
                insertTerm(result, sum_coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
}
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
void freePolynomial(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Polynomial 1: 5x^2 + 4x^1 + 2
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    // Polynomial 2: 3x^3 + 2x^2 + x
    insertTerm(&poly2, 3, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 1, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    addPolynomials(poly1, poly2, &result);

    printf("Resultant Polynomial after Addition: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}