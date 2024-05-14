#include<iostream>
using namespace std;
void quick(int arr[] , int low , int up);
int partition(int arr[],int low,int up);

int main()
{
int i;
int n;
cout<<"\nEnter the size of an array :";
cin>>n;
int arr[n];
cout<<"\nEnter the elements in an array :";
for(i=0;i<n;i++)
{
cin>>arr[i];
}
quick(arr,0,n-1); 
cout<<"\nThe quick sort result is :";
for(i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
return 0;
}/*End of main()*/

void quick(int arr[],int low,int up) 
{
int pvtloc;
if(low>=up)/*Terminating condition*/
return;
pvtloc=partition(arr,low,up);/*Returns the proper place of pivot*/
quick(arr,low,pvtloc-1);/*Sort the left sublist using quick sort recursively*/ 
quick(arr,pvtloc+1,up);/*Sort the right sublist using quick sort recursively*/  
}/*End of quick()*/

int partition(int arr[],int low,int up)
{
int temp,i,j,pivot;
i = low+1; 
j = up;
pivot = arr[low];
while(i<=j)
{
while((arr[i]<pivot)&&(i<up))
i++;
while(arr[j]>pivot)
j--;
if(i<j)
{
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
i++;
j--;
}
else
{
i++;
}
}
arr[low] = arr[j];
arr[j] = pivot;
return j;
}/*End of partition()*/

/*
Enter the size of an array :9

Enter the elements in an array :3 5 4 6 1 8 2 7 9

The quick sort result is :1 2 3 4 5 6 7 8 9 
*/

