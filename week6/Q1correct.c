#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node* link;
};

void display(struct node* first) {
    struct node* t = first;
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    do {
        printf("%d", t->d);
        t = t->link;
        if (t != first) printf(" -> ");
    } while (t != first);
    printf("\n");
}

int main() {
    struct node *first = NULL, *last = NULL, *t, *temp;
    int op, choice, fl, ele;

    // Initial list creation
    do {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("enter element: ");
        scanf("%d", &temp->d);
        temp->link = NULL;

        if (last == NULL) {
            first = last = temp;
            last->link = first; // circular link
        } else {
            temp->link = last->link; // last->link is first
            last->link = temp;
            last = temp;
        }

        printf("enter 1 to continue: ");
        scanf("%d", &op);
    } while (op == 1);

    display(first);

    do {
        printf("\nChoose operation:\n");
        printf("1: Insert at end\n");
        printf("2: Delete from beginning\n");
        printf("3: Delete from end\n");
        printf("4: Display list\n");
        printf("0: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Insert at end
            temp = (struct node*)malloc(sizeof(struct node));
            printf("Insert element: ");
            scanf("%d", &ele);
            temp->d = ele;
            temp->link = NULL;

            printf("Insert using first(1) or last(2) pointer? ");
            scanf("%d", &fl);

            if (fl == 1) {
                // Using first pointer to insert at end
                if (first == NULL) {
                    first = last = temp;
                    last->link = first;
                } else {
                    t = first;
                    while (t->link != first)
                        t = t->link;

                    t->link = temp;
                    temp->link = first;
                    last = temp;
                }
            } else if (fl == 2) {
                // Using last pointer to insert at end
                if (last == NULL) {
                    first = last = temp;
                    last->link = first;
                } else {
                    temp->link = last->link;
                    last->link = temp;
                    last = temp;
                }
            } else {
                printf("Invalid choice.\n");
                free(temp);
            }
            display(first);
            break;

        case 2: // Delete from beginning
            if (first == NULL) {
                printf("List is empty. Cannot delete.\n");
                break;
            }

            printf("Delete using first(1) or last(2) pointer? ");
            scanf("%d", &fl);

            if (first == last) {
                // Only one node
                free(first);
                first = last = NULL;
            } else if (fl == 1) {
                // Using first pointer to delete first node
                t = first;
                while (t->link != first)
                    t = t->link; // find last node

                t->link = first->link;
                temp = first;
                first = first->link;
                free(temp);
            } else if (fl == 2) {
                // Using last pointer to delete first node
                temp = last->link; // first node
                last->link = temp->link;
                first = last->link;
                free(temp);
            } else {
                printf("Invalid choice.\n");
            }
            display(first);
            break;

        case 3: // Delete from end
            if (first == NULL) {
                printf("List is empty. Cannot delete.\n");
                break;
            }

            printf("Delete using first(1) or last(2) pointer? ");
            scanf("%d", &fl);

            if (first == last) {
                // Only one node
                free(first);
                first = last = NULL;
            } else if (fl == 1) {
                // Using first pointer to delete last node
                t = first;
                while (t->link != last)
                    t = t->link; // find node before last

                t->link = first;
                free(last);
                last = t;
            } else if (fl == 2) {
                // Using last pointer to delete last node
                t = last->link; // first node
                temp = NULL;
                while (t->link != last) {
                    t = t->link;
                }
                // t now points to node before last
                temp = last;
                t->link = last->link;
                last = t;
                free(temp);
            } else {
                printf("Invalid choice.\n");
            }
            display(first);
            break;

        case 4: // Display list
            display(first);
            break;

        case 0:
            printf("Exiting.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    // Free remaining nodes before exit
    while (first != NULL) {
        if (first == last) {
            free(first);
            first = last = NULL;
        } else {
            temp = first;
            first = first->link;
            free(temp);
        }
    }

    return 0;
}

