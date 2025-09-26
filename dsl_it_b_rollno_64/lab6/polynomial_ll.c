#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial{
int coeff;
int exp;
struct polynomial *next;
struct polynomial *prev;
}polynomial;

void init_node(polynomial *node, int coeff, int exp) {
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    node->prev = NULL;
}
#


void add_polynomials(polynomial **result, polynomial *head1, polynomial *head2) {
    *result = NULL;
    polynomial *tail_res = NULL;

    while (head1 != NULL && head2 != NULL) {
        polynomial *node = NULL;

        if (head1->exp == head2->exp) {
            int sum = head1->coeff + head2->coeff;
            if (sum != 0) {
                node = (polynomial*)malloc(sizeof(polynomial));
                init_node(node, sum, head1->exp);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exp > head2->exp) {
            node = (polynomial*)malloc(sizeof(polynomial));
            init_node(node, head1->coeff, head1->exp);
            head1 = head1->next;
        }
        else {
            node = (polynomial*)malloc(sizeof(polynomial));
            init_node(node, head2->coeff, head2->exp);
            head2 = head2->next;
        }

        if (node) {
            if (*result == NULL) {
                *result = node;
                tail_res = node;
            } else {
                tail_res->next = node;
                node->prev = tail_res;
                tail_res = node;
            }
        }
    }

    // Append leftover nodes
    while (head1 != NULL) {
        polynomial *node = (polynomial*)malloc(sizeof(polynomial));
        init_node(node, head1->coeff, head1->exp);

        if (*result == NULL) {
            *result = node;
            tail_res = node;
        } else {
            tail_res->next = node;
            node->prev = tail_res;
            tail_res = node;
        }
        head1 = head1->next;
    }

    while (head2 != NULL) {
        polynomial *node = (polynomial*)malloc(sizeof(polynomial));
        init_node(node, head2->coeff, head2->exp);

        if (*result == NULL) {
            *result = node;
            tail_res = node;
        } else {
            tail_res->next = node;
            node->prev = tail_res;
            tail_res = node;
        }
        head2 = head2->next;
    }
}

void display_polynomial(polynomial *head)
{
    if(head==NULL)
    {
        printf("The list is empty: ");
        return;
    }
    polynomial *current = head;
    while(current!=NULL)
    {
        printf("%dx", current->coeff);
        printf("^%d", current->exp);
        if(current->next!=NULL)
            printf("+");
        current= current->next;
    }
}
void create_polynomial(polynomial **head, polynomial **tail, int len)
{
    if (len==0)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }
    *head = (polynomial *)malloc(sizeof(polynomial));
    (*head)->prev = NULL;
    polynomial *current = *head;
    for(int i=0; i<len; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &current->coeff);
        printf("Enter the exponenent: ");
        scanf("%d", &current->exp);
        if(i!=len-1)
        {
            current->next = (polynomial *)malloc(sizeof(polynomial));
            current->next->prev = current;
            current= current->next;
        }
        else
        {
            *tail = current;
            current->next = NULL;
        }

    }
}
int main()
{
    polynomial *head1, *tail1, *head2, *tail2;
    polynomial *res;
    int len1, len2;
    printf("Enter the length of the first polynomial: ");
    scanf("%d", &len1);
    create_polynomial(&head1, &tail1, len1);
    printf("Enter the length of the second polynomial: ");
    scanf("%d", &len2);
    create_polynomial(&head2, &tail2, len2);
    printf("\nPolynomial 1: \n");
    display_polynomial(head1);
    printf("\nPolynomial 2: \n");
    display_polynomial(head2);
    add_polynomials(&res, head1, head2);
    printf("\nPolynomial res: \n");
    display_polynomial(res);
return 0;
}
