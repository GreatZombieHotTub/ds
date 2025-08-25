#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *llink, *rlink;};

int main() {
    struct node *head = NULL, *last = NULL, *t, *temp, *e;
    int op, ele, pos, key, cont;

    // linked list creation
    do {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("element: ");
        scanf("%d", &temp->d);
        temp->llink = temp->rlink = NULL;
        if (head == NULL) {
            head = last = temp;
        } else {
            last->rlink = temp;
            temp->llink = last;
            last = temp;
        }

        printf("1 to continue: ");
        scanf("%d", &op);
    } while (op == 1);

    printf("\n--- MENU ---\n");
    printf("1. append a new node to the end of the list\n");
    printf("2. remove the last node\n");
    printf("3. insert element at given pos\n");
    printf("4. delete element at given pos\n");
    printf("5. insert an element after a node containing a specific value\n");
    printf("6. insert an element before a node containing a specific value\n");
    printf("7. traverse the list forward\n");
    printf("8. traverse the list reverse\n");

    do {
        printf("enter choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                e = (struct node*)malloc(sizeof(struct node));
                printf("enter element to append: ");
                scanf("%d", &ele);
                e->d = ele;
                e->rlink = NULL;
                e->llink = last;
                if (head == NULL) {
                    head = last = e;}
                else {
                    last->rlink = e;
                    last = e;}
                break;

            case 2:
                if (last == NULL) {
                    printf("List is empty.\n");
                } else if (head == last) {
                    free(last);
                    head = last = NULL;
                } else {
                    t = last;
                    last = last->llink;
                    last->rlink = NULL;
                    free(t);
                }
                break;

            case 3:
                printf("enter element and pos: ");
                scanf("%d %d", &ele, &pos);
                e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->llink = e->rlink = NULL;

                if (pos == 1) {
                    e->rlink = head;
                    if (head != NULL) head->llink = e;
                    head = e;
                    if (last == NULL) last = e;
                } else {
                    t = head;
                    int count = 1;
                    while (t != NULL && count < pos) {
                        t = t->rlink;
                        count++;
                    }
                    if (t == NULL) {
                        if (last != NULL) {
                            last->rlink = e;
                            e->llink = last;
                            last = e;
                        } else {
                            head = last = e;
                        }
                    } else {
                        e->llink = t->llink;
                        e->rlink = t;
                        if (t->llink != NULL) t->llink->rlink = e;
                        t->llink = e;
                        if (pos == 1) head = e;
                    }
                }
                break;

            case 4:
                printf("enter pos to delete: ");
                scanf("%d", &pos);
                if (head == NULL) {
                    printf("List is empty.\n");
                    break;
                }
                t = head;
                int count = 1;
                while (t != NULL && count < pos) {
                    t = t->rlink;
                    count++;
                }
                if (t == NULL) {
                    printf("position too big\n");
                    break;
                }
                if (t == head) {
                    head = head->rlink;
                    if (head != NULL)
                        head->llink = NULL;
                    else
                        last = NULL;
                } else if (t == last) {
                    last = last->llink;
                    last->rlink = NULL;
                } else {
                    t->llink->rlink = t->rlink;
                    t->rlink->llink = t->llink;
                }
                free(t);
                break;

            case 5:
                printf("enter element and key: ");
                scanf("%d %d", &ele, &key);
                if (head == NULL) {
                    printf("list empty\n");
                    break;
                }
                t = head;
                while (t != NULL && t->d != key) {
                    t = t->rlink;
                }
                if (t == NULL) {
                    printf("key not found\n");
                    break;
                }
                e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->llink = t;
                e->rlink = t->rlink;
                if (t->rlink != NULL)
                    t->rlink->llink = e;
                t->rlink = e;
                if (t == last) last = e;
                break;

            case 6:
                printf("enter element and key: ");
                scanf("%d %d", &ele, &key);
                if (head == NULL) {
                    printf("list empty\n");
                    break;
                }
                t = head;
                while (t != NULL && t->d != key) {
                    t = t->rlink;
                }
                if (t == NULL) {
                    printf("key not found\n");
                    break;
                }
                e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->rlink = t;
                e->llink = t->llink;
                if (t->llink != NULL)
                    t->llink->rlink = e;
                t->llink = e;
                if (t == head) head = e;
                break;

            case 7:
                if (head == NULL) {
                    printf("linked list is empty.\n");
                } else {
                    t = head;
                    printf("linked list elements: ");
                    while (t != NULL) {
                        printf("%d -> ", t->d);
                        t = t->rlink;
                    }
                    printf("NULL\n");
                }
                break;

            case 8:
                if (last == NULL) {
                    printf("linked list is empty.\n");
                } else {
                    t = last;
                    printf("linked list elements: ");
                    while (t != NULL) {
                        printf("%d -> ", t->d);
                        t = t->llink;
                    }
                    printf("NULL\n");
                }
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("Enter 1 to continue: ");
        scanf("%d", &cont);
    } while (cont == 1);

    // Free all nodes
    while (head) {
        temp = head;
        head = head->rlink;
        free(temp);
    }

    return 0;
}
