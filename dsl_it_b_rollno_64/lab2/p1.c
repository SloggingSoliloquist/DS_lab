#include<stdio.h>
#include<stlib.h>
int min_array(int *arr, n)
{
min = *arr;
for(int i = 0; i<n; i++)
{
if (*(arr+i)<min)
{
min = *(arr+i);
}
}
return min;
}

int main()
{
int n, *arr, min;
printf("Enter the length of the array: ");
scanf("%d", &n);
arr = (int *)malloc(n*sizeof(int));
for(int i = 0; <n; i++)
{
printf("Enter the element: ");
scanf("%d", (arr+i));
}
min = min_array(arr, n);
printf("The minimum element is: ", min);
}
