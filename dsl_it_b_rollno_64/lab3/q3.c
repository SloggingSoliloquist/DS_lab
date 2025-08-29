#include<stdio.h>
#include<string.h>
struct Student{
char name[20];
int rollno;
int grade;
};

void read_struct(struct Student *s, int n)
{
for(int i = 0; i<n ; i++)
{
printf("Ente the student name: ");
scanf(" %[^\n]", (s+i)->name);
printf("Enter the student roll no.: ");
scanf(" %d", &(s+i)->rollno);
printf("Enter the student grade: ");
scanf(" %d", &(s+i)->grade);
}
}

void display_struct(struct Student *s, int n)
{
for(int i = 0; i<n; i++)
{
printf("%s\t%d\t%d\t\n", (s+i)->name, (s+i)->rollno, (s+i)->grade);
}
}

void max_struct(struct Student *s, int n)
{
int temp,  min;
char temp_char[20];
for(int i = 0; i<n-1; i++)
{
min= i;
for(int j =i; j<n; j++)
{
if((s+j)->grade>(s+min)->grade)
{
min = j;
}
}
if (min==i)
{
break;
}
else
{
strcpy(temp_char, (s+min)->name);
strcpy((s+min)->name, (s+i)->name);
strcpy((s+i)->name, temp_char);
temp =(s+i)->rollno;
(s+i)->rollno=(s+min)->rollno;
(s+min)->rollno= temp;
temp =(s+i)->grade;
(s+i)->grade=(s+min)->grade;
(s+min)->grade= temp;
}
}
printf("Max marks: \n%s\t%d\t%d\t\n", (s+min)->name, (s+min)->rollno, (s+min)->grade);
}
int main()
{
struct Student s[200];
int n;
printf("Enter the number of student records you want to read: ");
scanf("%d", &n);
read_struct(&s, n);
printf("Displaying the Student Records: \n");
display_struct(&s,n);
max_struct(s, n);

return 0;
}
