#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data, height;
    struct Node *left, *right;
} Node;

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int data) {
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;  // duplicates not allowed

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && key < root->left->data)
        return rotateRight(root);

    // Right Right
    if (balance < -1 && key > root->right->data)
        return rotateLeft(root);

    // Left Right
    if (balance > 1 && key > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left
    if (balance < -1 && key < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder traversal (balanced AVL): ");
    inorder(root);
    printf("\n");
}
