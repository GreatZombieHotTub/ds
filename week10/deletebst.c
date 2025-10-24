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


node* del(node* root, int key){
 if(root==NULL) return root;
   if (key < root->d)
        root->llink = del(root->llink, key);
    else if (key > root->d)
        root->rlink = del(root->rlink, key);
    else {
        // Case 1: No child
        if (root->llink == NULL && root->rlink == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->llink == NULL) {
            node* temp = root->rlink;
            free(root);
            return temp;
        }
        else if (root->rlink == NULL) {
            node* temp = root->llink;
            free(root);
            return temp;
        }

        // Case 3: Two children
        node* temp = min(root->rlink);
        root->d = temp->d; // Copy inorder successor’s data
        root->rlink = del(root->rlink, temp->d); // Delete the successor
    }

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



void inorder(node* root){
if(root==NULL) return;
inorder(root->llink);
printf("%d ", root->d);
inorder(root->rlink);
}

int main() {
    node* root = NULL;
    root = bstcreate(root);

    int x;
    printf("Enter value to delete: ");
    scanf("%d", &x);

    root = del(root, x);  // update root!

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

