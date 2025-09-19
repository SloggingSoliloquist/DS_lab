#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
char rev_str[MAX_SIZE];
int top=-1;
void push_to_stack(char str[100])
{
    for(int i = 0; i<strlen(str); i++)
    {
        rev_str[++top]= str[i];
    }
}
int is_palindrome(char str[100])
{
    push_to_stack(str);
    for(int i =0; i<strlen(str); i++)
    {
        if(rev_str[top--]!=str[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char str[100];
    printf("Enter the string you want to check: ");
    scanf("%[^\n]", str);
    if(is_palindrome(str)==1)
    {
        printf("\nString entered is a palindrome. ");
    }
    else
    {
        printf("\nNot a palindrome. ");
    }
return 0;
}
