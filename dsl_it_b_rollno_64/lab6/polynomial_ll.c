#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial{
int coeff;
int exp;
struct polynomial *next;
struct polynomial *prev;
}polynomial;

void add_polynomials(polynomial **result, polynomial **head1, polynomial **head2)
{
    polynomial *current1 = *head1;
    polynomial *current2 = *head2;
    *result = NULL;
    polynomial *current_res = *result;
    while(current1!=NULL && current2!=NULL)
    {
        if(current1->exp == current2->exp)
        {
            if(*result==NULL)
            {
                *result = (polynomial *)malloc(sizeof(polynomial));
                (*result)->coeff=(current1->coeff +current2->coeff);
                (*result)->exp= current1->exp;
                current1 = current1->next;
                current2 = current2->next;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current_res = current_res->next;
            }
            else
            {
                current_res->coeff = (current1->coeff +current2->coeff);
                current_res->coeff = current1->exp;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current1 = current1->next;
                current2 = current2->next;
                current_res = current_res->next;
            }
        }
        else if(current1->exp > current2->exp)
        {
            if(*result==NULL)
            {
                *result = (polynomial *)malloc(sizeof(polynomial));
                (*result)->coeff=(current1->coeff);
                (*result)->exp= current1->exp;
                current1 = current1->next;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current_res = current_res->next;
            }
            else
            {
                current_res->coeff = (current1->coeff);
                current_res->coeff = current1->exp;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current1 = current1->next;
                current_res = current_res->next;
            }
        }
        else
        {
            if(*result==NULL)
            {
                *result = (polynomial *)malloc(sizeof(polynomial));
                (*result)->coeff=(current2->coeff);
                (*result)->exp= current2->exp;
                current2 = current2->next;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current_res = current_res->next;
            }
            else
            {
                current_res->coeff = (current2->coeff);
                current_res->coeff = current2->exp;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current2 = current2->next;
                current_res = current_res->next;
            }

        }
    }
    while(current1!=NULL)
    {
            if(*result==NULL)
            {
                *result = (polynomial *)malloc(sizeof(polynomial));
                (*result)->coeff=(current1->coeff);
                (*result)->exp= current1->exp;
                current1 = current1->next;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current_res = current_res->next;
            }
            else
            {
                current_res->coeff = (current1->coeff);
                current_res->coeff = current1->exp;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current1 = current1->next;
                current_res = current_res->next;
            }
    }
    while(current2!=NULL)
    {
            if(*result==NULL)
            {
                *result = (polynomial *)malloc(sizeof(polynomial));
                (*result)->coeff=(current2->coeff);
                (*result)->exp= current2->exp;
                current2 = current2->next;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current_res = current_res->next;
            }
            else
            {
                current_res->coeff = (current2->coeff);
                current_res->coeff = current2->exp;
                (current_res)->next= (polynomial*)malloc(sizeof(polynomial));
                current2 = current2->next;
                current_res = current_res->next;
            }
    }
    current_res = NULL;

}
void display_polynomial(polynomial *head)
{
    printf("Entered");
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
    printf("Polynomial Res: ");
    display_polynomial(head2);
    add_polynomials(&res, &head1, &head2);
    display_polynomial(res);
return 0;
}
