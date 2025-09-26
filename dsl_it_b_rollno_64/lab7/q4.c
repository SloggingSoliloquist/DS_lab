#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Push integer onto stack
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop integer from stack
int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i, op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++) {
        char token = exp[i];

        if (isdigit(token)) {
            // Convert char digit to int and push
            push(token - '0');
        } else {
            // Operator → pop two operands
            op2 = pop();
            op1 = pop();
            switch (token) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': {
                    result = 1;
                    for (int k = 0; k < op2; k++) result *= op1;
                    break;
                }
                default:
                    printf("Invalid operator: %c\n", token);
                    exit(1);
            }
            // Push result back
            push(result);
        }
    }
    // Final result is on top
    return pop();
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}
