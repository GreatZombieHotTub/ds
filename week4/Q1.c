//SINGLY LINKED LIST
//first create node structure and accept a linked list
//make menu driven program in main
//display the linked list with its changes after every function
//do while loop

#include <stdio.h>
#include <string.h>
struct node{
int d;
struct node* link; };

void display(struct node* head) {
if (head == NULL){
printf("Linked list is empty.\n");
return;
}
struct node* t=head;
printf("Linked list elements: ");
while (t!= NULL) {
printf("%d -> ", t->d);
t = t->link;
}
printf("NULL\n");
}

void main(){
struct node *t,*head=NULL, *temp;
//linked list creation.
int op;
do{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter element: ");
scanf("%d",&temp->d);
temp->link=NULL;
if(head==NULL){
    head=temp;
    t=temp;}
else{
    t->link=temp;
    t=temp;
}
printf("enter 1 to continue: ");
scanf("%d", &op);
}while(op==1);

printf("original list: ");
display(head);

/*Insert an element before another specified element in the list
(Example: Insert 10 before 25)
➢ Insert an element after another specified element in the list
(Example: Insert 40 after 25)
➢ Delete a specified element from the list
(Example: Delete node containing 15)
➢ Traverse the list and display all elements
➢ Reverse the linked list
(Modify the links such that the list is reversed)
➢ Sort the list in ascending order
(Using Bubble Sort or any appropriate algorithm on linked list)
➢ Delete every alternate node in the list
(Starting from the second node)
➢ Insert an element into a sorted linked list while maintaining the sorted order
(Example: Insert 28 into a list that is already sorted)*/

printf("enter 1 to insert element before key \n");
printf("enter 2 to insert element after key \n");
printf("enter 3 to delete node using key \n");
printf("enter 4 to display list \n");
printf("enter 5 to reverse list \n");
printf("enter 6 sort in ascending order\n");
printf("enter 7 delete every alternate node\n");
printf("enter 8 insert element in sorted list (note: pls sort list before doing this)\n");
int choice, cont;
struct node* e=(struct node*)malloc(sizeof(struct node));
do{
int ele,key;
printf("enter choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
    printf("enter element to be inserted and key:");
    scanf("%d %d",&ele, &key);
    e->d=ele;
    e->link=NULL;
    t=head; temp=head;
    if(head->d==key){
        e->link=head;
        head=e;
    }
    while(t->link!=NULL){
        t=t->link;
        if(t->d==key){
            e->link=t;
            temp->link=e;
        }
        temp=t;
    }
    break;
case 2:
    t=head; temp=head;
    printf("enter element to be inserted and key:");
    scanf("%d %d",&ele, &key);
    e->d=ele;
    e->link=NULL;
    while(t!=NULL){
        if(t->d==key){
            e->link=t->link;
            t->link=e;
        }} break;
case 3:
    t=head; temp=head;
    printf("enter element to be deleted:");
    scanf("%d", &key);
    if(head->d==key){
        head=head->link;
    }
    while(t!=NULL){
        t=t->link;
        if(t->d==key){
                temp->link=t->link;
                t=t->link;}
        temp=temp->link;
    } break;
case 4:
    display(head);
case 5:
    //reverse
    t=head;
    struct node* prev, next;
    prev=NULL; next=NULL;
    while(t!=NULL){
        next=t->link;
        t->link=prev;
        prev=t;
        t=next;
    }
    head=prev; break;
case 6:
    t=head; temp=head;
    //sorting ascending
    int n=0,small;
    while(t!=NULL){ n++;}
    t=head;
    for(int i=0;i<n-1; i++){
        temp=temp->link;
        small=temp->d;
        for(int j=0; j<n-i-1; j++){
            if()
        }
    }

case 7:


break;

case 8:
    t=head; temp=head;
     printf("enter element to be inserted:");
    scanf("%d",&key);
    e->d=key;
    e->link=NULL;
//first find which position to insert it before and then insert there


    }
break;












    }



printf("enter 1 to continue");
scanf("%d", %cont);
}while(cont==1);






freeList(head);



}
