#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *llink, *rlink;
};

// Create polynomial, returns the head pointer
struct node* create() {
    struct node *head = NULL, *temp, *t;
    int op;
    do {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter coeff and exp: ");
        scanf("%d %d", &temp->coeff, &temp->exp);
        temp->llink = temp->rlink = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            t = head;
            while (t->rlink != NULL) t = t->rlink;
            t->rlink = temp;
            temp->llink = t;
        }

        printf("1 to continue: ");
        scanf("%d", &op);
    } while (op == 1);

    return head;
}

// Display polynomial
void display(struct node* head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->rlink != NULL) printf(" + ");
        temp = temp->rlink;
    }
    printf("\n");
}

// Add two polynomials
struct node* add(struct node *heada, struct node *headb) {
    struct node *headc = NULL, *temp, *t3 = NULL;

    while (heada != NULL && headb != NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->llink = temp->rlink = NULL;

        if (heada->exp > headb->exp) {
            temp->coeff = heada->coeff;
            temp->exp = heada->exp;
            heada = heada->rlink;
        } else if (heada->exp < headb->exp) {
            temp->coeff = headb->coeff;
            temp->exp = headb->exp;
            headb = headb->rlink;
        } else {
            temp->coeff = heada->coeff + headb->coeff;
            temp->exp = heada->exp;
            heada = heada->rlink;
            headb = headb->rlink;
            // Skip terms with 0 coefficient
            if (temp->coeff == 0) {
                free(temp);
                continue;
            }
        }

        if (headc == NULL) {
            headc = temp;
            t3 = temp;
        } else {
            t3->rlink = temp;
            temp->llink = t3;
            t3 = temp;
        }
    }

    // Add remaining terms from heada
    while (heada != NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = heada->coeff;
        temp->exp = heada->exp;
        temp->llink = temp->rlink = NULL;
        if (headc == NULL) {
            headc = temp;
            t3 = temp;
        } else {
            t3->rlink = temp;
            temp->llink = t3;
            t3 = temp;
        }
        heada = heada->rlink;
    }

    // Add remaining terms from headb
    while (headb != NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = headb->coeff;
        temp->exp = headb->exp;
        temp->llink = temp->rlink = NULL;
        if (headc == NULL) {
            headc = temp;
            t3 = temp;
        } else {
            t3->rlink = temp;
            temp->llink = t3;
            t3 = temp;
        }
        headb = headb->rlink;
    }

    return headc;
}

int main() {
    struct node *heada = NULL, *headb = NULL, *headc = NULL;

    printf("Enter first polynomial:\n");
    heada = create();

    printf("Enter second polynomial:\n");
    headb = create();

    printf("\nPolynomial A: ");
    display(heada);

    printf("Polynomial B: ");
    display(headb);

    headc = add(heada, headb);

    printf("Sum polynomial: ");
    display(headc);

    return 0;
}

