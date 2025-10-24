#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// i) Recursive function to create a binary tree
struct Node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;  // base case — no node

    struct Node* root = newNode(data);
    printf("Enter left child of %d\n", data);
    root->left = createTree();
    printf("Enter right child of %d\n", data);
    root->right = createTree();

    return root;
}

// Helper function to find the height of the tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Function to print nodes at a given level
void printLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// ii) Function to print the tree in level-order (recursively)
void levelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

int main() {
    struct Node* root = NULL;

    printf("Create the binary tree:\n");
    root = createTree();

    printf("\nLevel-order traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
