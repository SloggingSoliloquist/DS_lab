#include<stdio.h>
int main(){
int arr[100];
int n, el, found = 0;
printf("Enter the length of the array: ");
scanf("%d", &n);
for(int i = 0; i<n; i++)
{
printf("Enter element number %d: ", i);
scanf("%d", &arr[i]);
}
printf("Enter the element to be searched for: ");
scanf("%d", &el);

for(int i=0; i<n; i++)
{
if (arr[i]==el){
printf("Element found at index: %d", i);
found=1;
break;
}
}
if (found==0)
{
printf("Element not found");
}
return 0;
}
