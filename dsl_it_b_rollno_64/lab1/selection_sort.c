#include<stdio.h>
int main(){
int arr[100];
int n, j,i,min,temp;
printf("Enter the length of the array: ");
scanf("%d", &n);
for( i = 0; i<n; i++)
{
printf("Enter element number %d: ", i+1);
scanf("%d", &arr[i]);
}
for(i=0; i<n-1; i++)
{
min = i;
for(j=i; j<n;j++)
{
if (arr[j]<arr[min])
{
min = j;
}
}
temp = arr[min];
arr[min]=arr[i];
arr[i]=temp;
}
printf("\n The sorted array is: \n[");
for (int i= 0; i<n; i++)
{
    printf("%d ", arr[i]);
}
printf("]");
return 0;
}
