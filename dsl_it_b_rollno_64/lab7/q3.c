#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stk{
char val;
struct stk *next;
};
struct output{
char val;
struct output *next;
};

void attach_node_to_op(struct output **node, char c)
{
    if(*node==NULL)
            {
                *node= (struct output*)malloc(sizeof(struct output));
                (*node)->val =c;
                (*node)->next= NULL;
            }
            else
            {
                struct output *new_node = (struct output*)malloc(sizeof(struct output));
                new_node->val = c;
                new_node->next = NULL;
                (*node)->next = new_node;
            }
}
void attach_node_to_stk(struct stk **head, char c)
{
    if(*head==NULL)
            {
                *head= (struct stk*)malloc(sizeof(struct stk));
                (*head)->val =c;
                (*head)->next= NULL;
            }
            else
            {
                struct stk *current = (struct stk*)malloc(sizeof(struct stk));
                current->val = c;
                current->next = *head;
                *head = current;
            }
}
int is_operator(char c)
{
    char operators[5] = "+-*/^";
    for(int i = 0; i<5; i++)
    {
        if (c==operators[i])
        {
            return 1;
        }
    }
    return 0;
}
int is_operand(char c)
{
    return((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'));
}
int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
}

int has_higher_or_equal_precedence(char c1, char c2)
{
    int p1 = precedence(c1);
    int p2 = precedence(c2);
    if(p1==p2)
    {
        if(c1=='^')
        {
            return 0;
        }
        return 1;
    }
    return (p1>p2);
}

void convert_to_postfix(char infix[100], char str[100], struct stk **head_stk)
{
    int i = 0, j = 0;

    strcat(infix, ")");
    *head_stk = (struct stk*)malloc(sizeof(struct stk));
    (*head_stk)->val= '(';
    (*head_stk)->next= NULL;
    struct stk* current_stk = (*head_stk);
    char c=infix[0];
    while(infix[i]!='\0')
    {
        if (is_operand(c)==1)
        {
            printf("no");
            printf("%c", c);
            str[j++]=c;

        }
        else if(c=='(')
        {
            attach_node_to_stk(head_stk, c);
        }
        else if(is_operator(c))
        {
            while(*head_stk!=NULL && has_higher_or_equal_precedence((*head_stk)->val, c))
                  {
                        str[j++]=(*head_stk)->val;
                        struct stk *temp = (*head_stk);
                        *head_stk = (*head_stk)->next;
                        free(temp);
                  }
                  attach_node_to_stk(head_stk, c);
        }
        else if(c==')')
        {
            while(*head_stk!=NULL && (*head_stk)->val!='(')
                  {
                        str[j++]=(*head_stk)->val;
                        struct stk *temp = (*head_stk);
                        *head_stk = (*head_stk)->next;
                        free(temp);
                  }
                        struct stk *temp = (*head_stk);
                        *head_stk = (*head_stk)->next;
                        free(temp);
        }
        i++;
        c= infix[i];
    }
    printf("The evaluated expression: %s", str);
}

void display_ll(struct output *head)
{
    struct output *current = head;
    while(current!=NULL)
    {
        printf("%d->", current->val);
    }
    printf("NULL");
}
int main()
{
    char infix[100];
    char postfix[100];
    struct stk *head_stk =NULL;
    struct output *head_op =NULL;
    printf("Enter the expression you want to evaluate: ");
    scanf("%[^\n]", infix);
    convert_to_postfix(infix, postfix, &head_stk);
return 0;
}
