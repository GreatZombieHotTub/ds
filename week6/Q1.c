//CIRCULAR SINGLY LINKED LIST
/*1. insert at end using last ptr
2.deletion from beginnning/end using both first and last
3.display list after every operation (implies making a display function outside)*/


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
    else{
    printf("Linked list elements: ");
    while (t->link !=first) {
        printf("%d -> ", t->d);
        t = t->link;
    }
    printf("%d", t->d);
}}

int main(){
 struct node *first, *last,*t,*temp;
 int op,choice,fl, ele;
 first=last=NULL;

 do{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter element: ");
    scanf("%d", &temp->d);
    temp->link=NULL;
    if(last==NULL){
        first=last=temp; //without this line, linked list will show empty as display uses first.
        last->link=last;}
    else{
        temp->link=last->link;
        last->link=temp;
        last=temp;
    }
    printf("enter 1 to continue");
    scanf("%d", &op);
 }while(op==1);
last->link=first;
display(first);
//printf("%d", last->link->d);

do{
    printf("enter choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        struct node* e=(struct node*)malloc(struct node);
        printf("insert element: ");
        scanf("%d", &ele);
        e->link=NULL;
        printf("using first(1)or last(2) pointer");
        scanf("%d",&fl);
        if(fl==1){
            t=first;
            while(t->link!=first)
                    t=t->link;

           e->link->t;
           t->link=e;}
        else if(f==2){
            if(last==NULL){
                last=temp;
                last->link=last;
            }
            else{
                e->link=last-link;
                last->link=e;
                last=e;
            }}
            break:
    case 2: //deletion from beginning
        printf("using first(1)or last(2) pointer");
        scanf("%d",&fl);
        if(fl==1){ //deleting using first pointer
            t=first;
            while(t->link!=first)
                t=t->link;
            t->link=temp;
            t->link=t->link->link;
            first=t->link;
            free(temp);
        }
        else if(fl==2){// deleting head using last pointer
            temp=last->link;
            last->link=last->link->link;
            free(temp);
            first=last->link;
        }
       break;

    case 3://deletion from end
                printf("using first(1)or last(2) pointer");
        scanf("%d",&fl);
        if(fl==1){ //deleting using first pointer






     }





















}



return 0;
}
