#include <stdio.h>
#include <stdlib.h>

struct node {
 char c;
 struct node* link;
};

int main(){
struct node *head, *t,*temp;
int op;

    // Linked list creation
do {
   temp = (struct node*)malloc(sizeof(struct node));
   printf("Enter element: ");
   scanf("%d", &temp->d);
   temp->link = NULL;
   if (head == NULL) {
        head = temp;
        t = temp;}
   else {
        t->link = temp;
        t = temp;
        }
        printf("Enter 1 to continue: ");
        scanf("%d", &op);
    } while (op == 1);



















return 0;}

