#include<stdio.h>
#include<stdlib.h>
int sel_sort(int *arr, int n, int low, int high)
{
int min, step= 0, temp;


min = low;
for(int j = low; j<n; j++)
{
if (*(arr+j)<*(arr+min))
{
min = j;
}
}
if (min ==low)
{
return *(arr+min);
}
temp = *(arr+low);
*(arr+low) = *(arr+min);
*(arr+min)= temp;
low+=1;
sel_sort(arr, n, low, high);
}


int main()
{
int n, *arr, min;
printf("Enter the length of the array: ");
scanf("%d", &n);
arr = (int *)malloc(n*sizeof(int));

for(int i = 0; i<n; i++)
{
printf("Enter the element: ");
scanf("%d", (arr+i));
}
sel_sort(arr, n, 0, n-1);
printf("The sorted array is: \n");
for(int i = 0; i<n; i++)
{
printf("%d ", *(arr+i));

}
free(arr);
return 0;
}
