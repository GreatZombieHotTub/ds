#include<stdio.h>
#include<stdlib.h>
//no duplicates in bst
typedef struct node{
int d;
struct node* llink;
struct node* rlink; }node;


node* searchNode(node* root, int target)
{
    if (root == NULL || root->d == target) {
        return root;
    }
    if (root->d < target) {
        return searchNode(root->rlink, target);
    }
    return searchNode(root->llink, target);
}

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

int main(){
node* root=NULL;
root=bstcreate(root);
int x;
printf("enter val to search for: ");
scanf("%d", &x);
if (searchNode(root, x) != NULL) {
        printf("found");
    }
else {
        printf("not found");
    }}
//weird ass code wasnt working just because i made search func after create func, had to switvch
