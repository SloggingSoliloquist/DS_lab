#include<stdio.h>
int main(){
int arr[100];
int n, el, low = 0, high, mid,found = 0;
printf("Enter the length of the array: ");
scanf("%d", &n);
high = n-1;
for(int i = 0; i<n; i++)
{
printf("Enter element number %d: ", i+1);
scanf("%d", &arr[i]);
}
printf("Enter the element to be searched for: ");
scanf("%d", &el);

for(int i=0; i<=n; i++)
{
mid = (low+high)/2;
if (arr[mid]==el)
{
printf("Element found at  position: %d", mid+1);
found =1;
break;
}
else if (arr[mid]>el)
{
high = mid-1;
}
else
{
low = mid+1;
}
}
if (found==0)
{
printf("Element not found");
}
return 0;
}
