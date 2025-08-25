//SINGLY LINKED LIST
//first create node structure and accept a linked list
//make menu driven program in main
//display the linked list with its changes after every function
//do while loop

// SINGLY LINKED LIST MENU PROGRAM
#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node* link;
};

void display(struct node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node* t = head;
    printf("Linked list elements: ");
    while (t != NULL) {
        printf("%d -> ", t->d);
        t = t->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *t, *head = NULL, *temp;
    int op;

    // Linked list creation
    do {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter element: ");
        scanf("%d", &temp->d);
        temp->link = NULL;
        if (head == NULL) {
            head = temp;
            t = temp;
        } else {
            t->link = temp;
            t = temp;
        }
        printf("Enter 1 to continue: ");
        scanf("%d", &op);
    } while (op == 1);

    printf("Original list: ");
    display(head);

    printf("\n--- MENU ---\n");
    printf("1. Insert element before key\n");
    printf("2. Insert element after key\n");
    printf("3. Delete node using key\n");
    printf("4. Display list\n");
    printf("5. Reverse list\n");
    printf("6. Sort in ascending order\n");
    printf("7. Delete every alternate node\n");
    printf("8. Insert element in sorted list\n");
    printf("0. Exit\n");

    int choice, cont;
    do {
        int ele, key;
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Insert before key
            printf("Enter element to insert and key: ");
            scanf("%d %d", &ele, &key);
            {
                struct node* e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->link = NULL;

                if (head == NULL) {
                    printf("List is empty.\n");
                    free(e);
                } else if (head->d == key) {
                    e->link = head;
                    head = e;
                } else {
                    t = head;
                    temp = head;
                    while (t != NULL && t->d != key) {
                        temp = t;
                        t = t->link;
                    }
                    if (t == NULL) {
                        printf("Key %d not found.\n", key);
                        free(e);
                    } else {
                        e->link = t;
                        temp->link = e;
                    }
                }
            }
            display(head);
            break;

        case 2: // Insert after key
            printf("Enter element to insert and key: ");
            scanf("%d %d", &ele, &key);
            t = head;
            while (t != NULL && t->d != key)
                t = t->link;
            if (t == NULL) {
                printf("Key %d not found.\n", key);
            } else {
                struct node* e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->link = t->link;
                t->link = e;
            }
            display(head);
            break;

        case 3: // Delete node using key
            printf("Enter element to delete: ");
            scanf("%d", &key);
            if (head == NULL) {
                printf("List is empty.\n");
            } else if (head->d == key) {
                t = head;
                head = head->link;
                free(t);
            } else {
                t = head;
                temp = NULL;
                while (t != NULL && t->d != key) {
                    temp = t;
                    t = t->link;
                }
                if (t == NULL) {
                    printf("Key %d not found.\n", key);
                } else {
                    temp->link = t->link;
                    free(t);
                }
            }
            display(head);
            break;

        case 4: // Display
            display(head);
            break;

        case 5: // Reverse
        {
            struct node* prev = NULL;
            struct node* curr = head;
            struct node* next = NULL;
            while (curr != NULL) {
                next = curr->link;
                curr->link = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            printf("List reversed.\n");
            display(head);
        }
        break;

        case 6: // Sort ascending (Bubble sort)
        {
            if (head == NULL) break;
            int swapped;
            struct node* ptr1;
            struct node* lptr = NULL;
            do {
                swapped = 0;
                ptr1 = head;
                while (ptr1->link != lptr) {
                    if (ptr1->d > ptr1->link->d) {
                        int tempVal = ptr1->d;
                        ptr1->d = ptr1->link->d;
                        ptr1->link->d = tempVal;
                        swapped = 1;
                    }
                    ptr1 = ptr1->link;
                }
                lptr = ptr1;
            } while (swapped);
            printf("List sorted.\n");
            display(head);
        }
        break;

        case 7: // Delete every alternate node
            t = head;
            while (t != NULL && t->link != NULL) {
                struct node* del = t->link;
                t->link = del->link;
                free(del);
                t = t->link;
            }
            printf("Alternate nodes deleted.\n");
            display(head);
            break;

        case 8: // Insert in sorted list
            printf("Enter element to insert in sorted list: ");
            scanf("%d", &ele);
            {
                struct node* e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->link = NULL;

                if (head == NULL || head->d >= ele) {
                    e->link = head;
                    head = e;
                } else {
                    t = head;
                    while (t->link != NULL && t->link->d < ele)
                        t = t->link;
                    e->link = t->link;
                    t->link = e;
                }
            }
            display(head);
            break;

        case 0:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }

        printf("Enter 1 to continue: ");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}
