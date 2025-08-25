//DOUBLY LINKED LIST
//first create node structure and accept a linked list
//make menu driven program in main
#include <stdio.h>
#include <stdlib.h>

struct node{
 int d;
 struct node *llink, *rlink;}; //node structure

 /*1. append a new node to the end of the list
2. remove the last node
3. insert element at given pos
4. delete element at given pos
5. insert an element after a node containing a specific value
(e.g., Insert 40 after 25)
6. insert an element before a node containing a specific value
(e.g., Insert 10 before 25)
7.traverse the list in forward direction
(From head to tail)
8. traverse the list in reverse direction
(From tail to head – i.e., reverse traversal)*/


int main(){
 struct node *t, *temp, *head=NULL, *last;
 int op;
 do{
    temp=(struct node*)malloc(sizeof(struct node)); //creating the original linked list
    printf("element: ");
    scanf("%d", &temp->d);
    temp->llink=NULL;
    temp->rlink=NULL;
    if(head==NULL){
        head=temp;}
    else{
        t=head;
        while(t->rlink!=NULL){
            t=t->rlink;}
        temp->llink=t;
        t->rlink=temp;
        last=temp;}
    printf("1 to continue:");
    scanf("%d", &op);} while(op==1);

printf("\n--- MENU ---\n");
printf("1. append a new node to the end of the list");
printf("2. remove the last node");
printf("3. insert element at given pos");
printf("4. delete element at given pos");
printf("5. insert an element after a node containing a specific value");
printf("6. insert an element before a node containing a specific value ");
printf("7.traverse the list in forward direction");
printf("8. traverse the list in reverse direction");
int choice, cont, ele, key;
struct node* e = (struct node*)malloc(sizeof(struct node));

do{
    printf("enter choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("enter element to append: ");
            scanf("%d", &ele);
        //    struct node* e = (struct node*)malloc(sizeof(struct node));
            e->d = ele;
            e->llink = NULL; e->rlink=NULL;
            t=head;
            while(t->rlink!=NULL){
                t=t->rlink;}
            t->rlink=e;
            e->llink=t;
            t=e; last=t; free(e);
            break;
        case 2: //delete last node, pop
            t=head;
            while(t->rlink!=NULL){
                t=t->rlink;}
            last=t->llink;
            t->llink->rlink=NULL;
            t->llink=NULL;
            break;
        case 3:
            printf("enter element to insert and pos: ");
            scanf("%d %d", &ele, &key);
            {
             //   struct node* e = (struct node*)malloc(sizeof(struct node));
                e->d = ele;
                e->llink = NULL; e->rlink = NULL;
                if (key==1){
                    e->rlink=head;
                    head->llink=e;
                    head=e;}
                else{
                int count=1;
                t=head;
                while(count!=key && t!=NULL){
                    t=t->rlink;
                    count++;
                }
                if(t==NULL){
                    printf("postion too big");
                }
                else{
                    e->llink=t->llink;
                    e->rlink=t;
                    t->llink->rlink=e;
                    t->llink=e;
                }}}
                break;

        case 4:
            printf("enter pos to delete: ");
            scanf("%d", &key);
            int count=1;
            t=head;
            if(key==1){
                temp=head;
                head=head->rlink;
                head->llink=NULL;
                free(temp);

            }
            else{
            while(count!=key && t!=NULL){

                t=t->rlink;
                count++;
                }
            if(t==NULL){
                printf("postion too big");
                }
            else{
                t->rlink->llink=t->llink;
                t->llink->rlink=t->rlink;
                t=t->rlink;
                free(t);}}
            break;

        case 5:
            printf("enter element and key");
            scanf("%d %d",&ele, &key);
            e->d = ele;
            e->llink = NULL; e->rlink=NULL;
            t=head;
            if(last->d==key){
                last->rlink=e;
                e->llink=last;
                last=e;}
            else{
                while(t->d!=key && t!=NULL){
                    t=t->rlink;}
                if(t==NULL){
                    printf("key not found.");}
                else{
                    e->rlink=t->rlink;
                    t->rlink->llink=e;
                    t->rlink=e;
                    e->llink=t;}
            }
            break;

        case 6:
            printf("enter element and key");
            scanf("%d %d",&ele, &key);
            struct node* e = (struct node*)malloc(sizeof(struct node));
            e->d = ele;
            e->llink = NULL; e->rlink=NULL;
            t=head;
            if(head->d==key){
                head->llink=e;
                e->rlink=head;
                head=e;
            }
            else{
                while(t->d!=key && t!=NULL){
                    t=t->rlink;}
                if(t==NULL){
                    printf("key not found.");}
                else{
                t->llink->rlink=e;
                e->llink=t->llink;
                t->llink=e;
                e->rlink=t;
            }}
            break;
        case 7:
            printf("\ntraversing forward: \n");
            if (head == NULL) {
            printf("linked list is empty.\n");
            t = head;
            printf("linked list elements: ");
            while (t != NULL) {
            printf("%d -> ", t->d);
            t = t->rlink;}
            printf("NULL\n");
            break;

        case 8:
            printf("\nreverse traversal: \n");{
            if (head == NULL) {
            printf("linked list is empty.\n");
            return;}
            t = last;
            printf("Linked list elements: ");
            while (t != NULL) {
            printf("%d -> ", t->d);
            t = t->llink;}}
            printf("NULL\n");
            break;
        default:
            printf("invalid choice!\n");
        }

        printf("Enter 1 to continue: ");
        scanf("%d", &cont);
    }} while (cont == 1);
 while (head) {
        temp = head;
        head = head->rlink;
        free(temp);
    }
    return 0;
}
