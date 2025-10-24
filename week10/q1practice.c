#include<stdio.h>
#include<stdlib.h>
//no duplicates in bst
typedef struct node{
int d;
struct node* llink;
struct node* rlink; }node;

//bst creation
node* bstcreate(node* root){
 int val, ch;
 node* parent;

 do{
 printf("enter val: ");
 scanf("%d", &val);

 node* temp=(node*)malloc(sizeof(node));
 temp->llink=temp->rlink=NULL;
 temp->d=val;
 if(root==NULL) root=temp;
 else{
    node* t=root;
    while(t!=NULL){
        parent=t;
        if(t->d>temp->d){ t=t->llink;}
        else if(t->d<temp->d){ t=t->rlink;}
        else { printf("duplicates not allowed??!\n"); free(temp); temp=NULL; break;}}
    if(temp!=NULL){if(temp->d > parent->d) parent->rlink=temp;
    else parent->llink=temp;}
 }
 printf("continue?: "); scanf("%d", &ch);
 }while(ch==1);
 return root;
}


//inorder traversal
void inorder(node* root){
if(root==NULL) return;
inorder(root->llink);
printf("%d ", root->d);
inorder(root->rlink);
}

void preorder(node* root){
if(root==NULL) return;
printf("%d ", root->d);
preorder(root->llink);
preorder(root->rlink);
}

void postorder(node* root){
if(root==NULL) return;
postorder(root->llink);
postorder(root->rlink);
printf("%d ", root->d);
}
int main(){
node* root=NULL;
root=bstcreate(root);
printf("inorder: ");
inorder(root);
printf("\npostorder: ");
postorder(root);
printf("\npreorder: ");
preorder(root);
}
