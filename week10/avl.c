#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct TreeNode {
    int data;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new node
TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Get height of node
int height(TreeNode* root) {
    if (root == NULL) return 0;
    return root->height;
}

// Get balance factor
int getBalance(TreeNode* root) {
    if (root == NULL) return 0;
    return height(root->left) - height(root->right);
}

// Right rotation
TreeNode* rightRotate(TreeNode* root) {
    TreeNode* child = root->left;
    TreeNode* childRight = child->right;
    child->right = root;
    root->left = childRight;

    root->height = 1 + MAX(height(root->left), height(root->right));
    child->height = 1 + MAX(height(child->left), height(child->right));

    return child;
}

// Left rotation
TreeNode* leftRotate(TreeNode* root) {
    TreeNode* child = root->right;
    TreeNode* childLeft = child->left;
    child->left = root;
    root->right = childLeft;

    root->height = 1 + MAX(height(root->left), height(root->right));
    child->height = 1 + MAX(height(child->left), height(child->right));

    return child;
}

// Insert node in AVL Tree
TreeNode* createAVLTree(TreeNode* root, int data) {
    if (root == NULL)
        return createTreeNode(data);

    if (data < root->data)
        root->left = createAVLTree(root->left, data);
    else if (data > root->data)
        root->right = createAVLTree(root->right, data);
    else
        return root; // duplicates not allowed

    // Update height
    root->height = 1 + MAX(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Left Left case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Traversals
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    int n, ele;
    TreeNode* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &ele);
        root = createAVLTree(root, ele);
    }

    printf("\nInorder Traversal (sorted): ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
