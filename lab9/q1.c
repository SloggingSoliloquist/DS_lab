#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for level order tree creation
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

int isEmptyQ(struct Queue* q) {
    return q->front == q->rear;
}

// Stack structure for traversals
struct Stack {
    struct Node* arr[100];
    int top;
};

void push(struct Stack* stack, struct Node* node) {
    stack->arr[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree using level order input
struct Node* buildTree() {
    struct Queue q;
    q.front = q.rear = -1;

    int data;
    printf("Enter root data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    struct Node* root = newNode(data);
    enqueue(&q, root);

    while (!isEmptyQ(&q)) {
        struct Node* current = dequeue(&q);
        int leftData, rightData;

        printf("Enter left child of %d (-1 for no node): ", current->data);
        scanf("%d", &leftData);
        if (leftData != -1) {
            current->left = newNode(leftData);
            enqueue(&q, current->left);
        }

        printf("Enter right child of %d (-1 for no node): ", current->data);
        scanf("%d", &rightData);
        if (rightData != -1) {
            current->right = newNode(rightData);
            enqueue(&q, current->right);
        }
    }

    return root;
}

// Traversals (Iterative)
void inorderIterative(struct Node* root) {
    struct Stack stack;
    stack.top = -1;
    struct Node* curr = root;

    while (curr != NULL || !isEmpty(&stack)) {
        while (curr != NULL) {
            push(&stack, curr);
            curr = curr->left;
        }
        curr = pop(&stack);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderIterative(struct Node* root) {
    if (root == NULL) return;
    struct Stack stack;
    stack.top = -1;
    push(&stack, root);

    while (!isEmpty(&stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
}

void postorderIterative(struct Node* root) {
    if (root == NULL) return;
    struct Stack stack1, stack2;
    stack1.top = stack2.top = -1;

    push(&stack1, root);
    while (!isEmpty(&stack1)) {
        struct Node* node = pop(&stack1);
        push(&stack2, node);

        if (node->left) push(&stack1, node->left);
        if (node->right) push(&stack1, node->right);
    }

    while (!isEmpty(&stack2)) {
        struct Node* node = pop(&stack2);
        printf("%d ", node->data);
    }
}

// Print parent of a given element
void printParent(struct Node* root, int key) {
    if (root == NULL) return;

    if ((root->left && root->left->data == key) ||
        (root->right && root->right->data == key)) {
        printf("Parent of %d is %d\n", key, root->data);
        return;
    }

    printParent(root->left, key);
    printParent(root->right, key);
}

// Tree height
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Print ancestors
int printAncestors(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;

    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root = buildTree();

    printf("\nInorder (Iterative): ");
    inorderIterative(root);

    printf("\nPreorder (Iterative): ");
    preorderIterative(root);

    printf("\nPostorder (Iterative): ");
    postorderIterative(root);
    printf("\n");

    int key;
    printf("\nEnter element to find its parent: ");
    scanf("%d", &key);
    printParent(root, key);

    printf("Height of tree: %d\n", height(root));

    printf("Enter element to print its ancestors: ");
    scanf("%d", &key);
    printf("Ancestors of %d: ", key);
    printAncestors(root, key);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
