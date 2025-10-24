#include<stdio.h>
#include<stdlib.h>
//no duplicates in bst
typedef struct node{
int d;
struct node* llink;
struct node* rlink; }node;

node* min(node* cur){
    while(cur != NULL && cur->llink != NULL) cur = cur->llink;
    return cur;
}


node* findMin(node* root) {
    if (root == NULL) return NULL; // Empty tree
    while (root->llink != NULL)
        root = root->llink;
    return root;
}

node* findMax(node* root) {
    if (root == NULL) return NULL; // Empty tree
    while (root->rlink != NULL)
        root = root->rlink;
    return root;
}
node* bstcreate(node* root) {
    int val, ch;
    do {
        printf("Enter val: ");
        scanf("%d", &val);

        node* temp = (node*)malloc(sizeof(node));
        temp->d = val;
        temp->llink = temp->rlink = NULL;

        if(root == NULL) {
            root = temp;
        } else {
            node* t = root;
            node* parent = NULL;

            while(t != NULL) {
                parent = t;
                if(val < t->d)
                    t = t->llink;
                else if(val > t->d)
                    t = t->rlink;
                else {
                    printf("Duplicate not allowed!\n");
                    free(temp);
                    temp = NULL;
                    break;
                }
            }

            if(temp != NULL) {
                if(val < parent->d)
                    parent->llink = temp;
                else
                    parent->rlink = temp;
            }
        }

        printf("continue?: ");
        scanf("%d", &ch);

    } while(ch == 1);

    return root;
}


int main() {
    node* root = NULL;
    root = bstcreate(root);

    node* minNode = findMin(root);
    node* maxNode = findMax(root);

    if(minNode) printf("Minimum: %d\n", minNode->d);
    if(maxNode) printf("Maximum: %d\n", maxNode->d);

    return 0;
}
