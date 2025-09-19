#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
char stk[MAX_SIZE];
int top = -1;

int matching_paranthesis(char str[100])
{
    for(int i= 0; i<strlen(str); i++)
    {
        if(str[i]=='(')
        {
            stk[++top]= str[i];
        }
        else if(str[i]==')')
        {
            if(top==-1)
            {
                return 0;
            }
            top--;
        }
    }
    if(top==-1)
    return 1;
    else
        return 0;
}
int main()
{
char exp[100];int cont=1;
do{
printf("Enter the expression: ");
scanf(" %[^\n]", exp);
if(matching_paranthesis(exp)==1)
{
    printf("Paranthesis are matching. ");
}
else
{
    printf("Paranthesis not matching. ");
}
printf("\nDo you want to continue? 0/1: ");
scanf("%d", &cont);}
while(cont==1);
return 0;
}
