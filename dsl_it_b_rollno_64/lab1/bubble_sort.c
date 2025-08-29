#include<stdio.h>
int main(){
int arr[100];
int n, pass, i,temp, swapped = 1;
printf("Enter the length of the array: ");
scanf("%d", &n);
for(int i = 0; i<n; i++)
{
printf("Enter element number %d: ", i+1);
scanf("%d", &arr[i]);
}
for(pass=n-1; pass>=0 &&swapped==1; pass--)
{
swapped = 0;
for(i=0; i<pass;i++)
{
if (arr[i]>arr[i+1])
{
 temp = arr[i];
 arr[i]=arr[i+1];
 arr[i+1]=temp;
 swapped = 1;
}
}
}
printf("\n The sorted array is: \n[");
for (int i= 0; i<n; i++)
{
    printf("%d ", arr[i]);
}
printf("]");
return 0;
}
