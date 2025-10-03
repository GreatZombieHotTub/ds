#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node *llink;
    struct Node *rlink;
}node;

node* create(int d) {
    node* temp=
      (node*)malloc(sizeof(node));
    temp->d= d;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void inorder(node* t){
if(t==NULL) return;
inorder(t->llink);
printf("%d ", t->d);
inorder(t->rlink);
}

void post(node *root){
 if(root==NULL) return;
 post(root->llink);
 post(root->rlink);
 printf("%d ", root->d);
}

void pre(node *root){
 if(root==NULL) return;
 printf("%d ",root->d);
 pre(root->llink);
 pre(root->rlink);
}

int parent(node *root,int target, int p){
 if(root==NULL) return -1;
 if(root->d==target) return p;
 int left=parent(root->llink, target, root->d);
 if(left!=-1)return left;
 return parent(root->rlink, target, root->d);
 }

int height(node *root){
 if(root==NULL) return -1;
 int lh=height(root->llink);
 int rh=height(root->rlink);
 return (lh>rh?lh:rh)+1;

}
int anc(node* root, int target) {
    if (root == NULL) return 0; // false
    if (root->d == target) return 1; // true
    // If target is present in left or right subtree
    if (anc(root->llink, target) || anc(root->rlink, target)) {
        printf("%d ", root->d); // print ancestor
        return 1;
    }

    return 0; // target not found in this subtree
}

int leaf(node* root) {
    if (root == NULL)
        return 0;           // no leaf here

    if (root->llink == NULL && root->rlink == NULL)
        return 1;           // this node is a leaf

    // recursively count leaves in left and right subtrees
    return leaf(root->llink) + leaf(root->rlink);
}

int main() {
    // Initialize and allocate memory for tree nodes
    node* n0 = create(1);
    node* n1 = create(2);
    node* n2 = create(3);
    node* n3 = create(4);
    node* n4 = create(5);
    node* n5 = create(6);
    //node *n6= create(7);

    // Connect binary tree nodes
    n0->rlink=n2; n2->rlink=n5;
    n0->llink=n1; n1->llink=n3; n1->rlink=n4;
    //n4->rlink=n6;

    //pre(n0);
    //printf("%d", parent(n0, 5, -1));
    //printf("%d", height(n0));
    //anc(n0, 6);
    printf("%d", leaf(n0));

    return 0;
}
//https://www.geeksforgeeks.org/dsa/construct-a-binary-in-level-order-using-recursion/
