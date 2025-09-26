#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

// Node structure for stack
typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

// Push onto stack
void push(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        exit(1);
    }
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

// Pop from stack
char pop() {
    if (top == NULL) {
        return -1;
    }
    Node* temp = top;
    char popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Peek at stack top
char peek() {
    if (top == NULL) return -1;
    return top->data;
}

// Check precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char token, x;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        token = infix[i];

        if (isalnum(token)) {
            // Operand → directly to output
            postfix[j++] = token;
        } 
        else if (token == '(') {
            push(token);
        } 
        else if (token == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } 
        else { 
            // Operator
            while (top != NULL && precedence(peek()) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    // Pop remaining operators
    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
