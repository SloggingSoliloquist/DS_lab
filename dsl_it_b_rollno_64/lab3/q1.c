#include<stdio.h>
int str_length(char str[200])
{
int i = 0;
while(str[i]!='\0')
{
i++;
}
return i;
}

void concat_str(char *str1, char *str2)
{
int i = 0;
while(*str1!='\0')
{
str1++;
}
while(*str2!='\0')
{
*str1=*str2;
*str1++;
*str2++;
}
*str1++='\0';
}

void compare_str(char *str1, char *str2)
{
int flag = 0;
int i = 0;
while(*str1!='\0' && *str2!='\0')
{
if(*str1!=*str2)
{
    break;
}
else if(*(str1+1)=='\0' && *(str2+1)=='\0')
{   flag = 1;
    printf("The two strings are equal.\n");
    break;
}
str1++;
str2++;

}
if (flag==0)
{
printf("The two strings are not equal. \n");
}
}

void insert_sub_str(char *str, char *insert_str, int insert_idx, int str_len, int insert_str_len)
{
for(int i=str_len; i>insert_idx-1; i--)
{
*(str+i+insert_str_len)=*(str+i);
*(str+i)="";
}

for(int i = insert_idx; i<insert_idx+insert_str_len; i++)
{
*(str+i)=*(insert_str);
insert_str++;
}

}

void delete_sub_str(char str[200], char del_str[200])
{
int pos = 0;
int found =0;
for (int i = 0; i<(str_length(str)-str_length(del_str)); i++)
{
int del_str_idx = 0;
while(str[i+del_str_idx]==del_str[del_str_idx] && del_str_idx<str_length(del_str))
{
del_str_idx++;
}
if(del_str_idx==str_length(del_str))
{
found=1;
pos = i;
break;
}
}
if(found==1)
{
printf("Substring found at index: %d", pos);
int j =0;
for(int i=0; i<(str_length(str)-str_length(del_str)); i++)
{
str[i+pos]= str[i+pos+str_length(del_str)];
j++;
}
}
else
{
printf("Substring not found");
}
}

int main()
{
int length1, length2, pos;
char str1[200], str1_copy[200], str2[200], str[200],insert_str[200], del_str[200];
printf("Enter string1: ");
scanf(" %[^\n]", str1);
length1 = str_length(str1);
printf("Enter the string2 you want to compare: ");
scanf(" %[^\n]", str2);
length2 = str_length(str2);
compare_str(str1, str2);
printf("Enter string1: ");
scanf(" %[^\n]", str1);
length1 = str_length(str1);
printf("Enter the string2 you want to concatenate: ");
scanf(" %[^\n]", str2);
concat_str(str1, str2);
printf("The concatenated string is: %s\n", str1);
printf("Enter the string you want to insert into: ");
scanf(" %[^\n]", str);
printf("Enter the string you want to insert into the previous string: ");
scanf(" %[^\n]", insert_str);
printf("Enter the position you want to insert into: ");
scanf("%d", &pos);
insert_sub_str(str, insert_str,pos, str_length(str), str_length(insert_str));
printf("The string with the insertion is: %s\n", str);
printf("Enter the string you want to delete from: ");
scanf(" %[^\n]", str);
printf("Enter the substring you want to delete: ");
scanf(" %[^\n]", del_str);
delete_sub_str(str, del_str);
printf("\n The string with the substring deleted is: %s", str);
return 0;
}
