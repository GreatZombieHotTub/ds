//polynomials rep as doubly linked lists

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *llink, *rlink;};

void create(struct node* head){

    struct node *temp,*t;
    int op;
      do {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("coeff and exp: ");
        scanf("%d %d", &temp->coeff,&temp->exp);
        temp->llink = temp->rlink = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            t=head;
            while(t->rlink!=NULL) t=t->rlink;
            t->rlink=temp;
            temp->llink=t;
        }

        printf("1 to continue: ");
        scanf("%d", &op);
    } while (op == 1);
    //free(t); free(temp);
    }

void add(struct node *heada, struct node *headb, struct node *headc){
 struct node *t1, *t2,*t3,*temp;
 int c1, c2;
 t1=heada; t2=headb; t3=headc;
 while(t1!=NULL && t2!=NULL){
    temp=(struct node*)malloc(sizeof(struct node));
    if(t1->exp>t2->exp){
        temp->coeff=t1->coeff;
        temp->exp=t1->exp;
        t1=t1->rlink;}
    else if(t1->exp<t2->exp){
        temp->coeff=t2->coeff;
        temp->exp=t2->exp;
        t2=t2->rlink;}
    else if(t1->exp==t2->exp){
        temp->coeff=t2->coeff+t1->coeff;
        temp->exp=t1->exp;
        t1=t1->rlink;
        t2=t2->rlink;}
 }
 while(t1!=NULL){
    t3->rlink=t1;
    t3=t3->rlink;
    t1=t1->rlink;}
while(t2!=NULL){
    t3->rlink=t2;
    t3=t2->rlink;
    t2=t2->rlink;}


t3=headc;
while(t3!=NULL){
    printf("%dx^%d", t3->coeff, t3->exp);
    if(t3->rlink==NULL) break;
    printf(" + ");
}}

int main(){
struct node *heada=NULL, *headb=NULL, *headc=NULL;
/*heada=(struct node*)malloc(sizeof(struct node));
heada->rlink=heada->llink= NULL;
headb=(struct node*)malloc(sizeof(struct node));
headb->rlink=heada->llink= NULL;
headc=(struct node*)malloc(sizeof(struct node));
headc->rlink=heada->llink= NULL;*/
printf("accepting a: \n");
create(heada);
printf("accepting b: \n");
create(headb);
add(heada, headb,headc);


return 0;
}

