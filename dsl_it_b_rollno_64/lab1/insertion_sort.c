#include<stdio.h>
int main(){
int arr[100];
int n, j,i,min,temp, curr_val, insert_idx;
printf("Enter the length of the array: ");
scanf("%d", &n);
for( i = 0; i<n; i++)
{
printf("Enter element number %d: ", i+1);
scanf("%d", &arr[i]);
}
for(i=0; i<n; i++)
{
curr_val = arr[i];
insert_idx =i;
j=i-1;
while(j>=0 && arr[j]>curr_val)
{
arr[j+1]= arr[j];
insert_idx=j;
j--;
}
arr[insert_idx]=curr_val;
}
printf("\n The sorted array is: \n[");
for ( i= 0; i<n; i++)
{
    printf("%d ", arr[i]);
}
printf("]");
return 0;
}
