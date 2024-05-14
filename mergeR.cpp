#include<iostream>
using namespace std;
void mergeR(int arr[],int low,int up);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void copy(int arr[],int temp[],int low,int up);

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
mergeR(arr,0,n-1);
cout<<"\nThe merge sort result is :";
for(i=0;i<n;i++)
{
cout<<arr[i]<<"\t";
}
return 0;
}/*End of main()*/

void mergeR(int arr[],int low,int up)
{
int mid;
int temp[10];
if(low<up)
{
mid=(low+up)/2;/*Find the middle element in an array*/
mergeR(arr,low,mid);/*Sort the left sublist recursively using merge sort*/
mergeR(arr,mid+1,up);/*Sort the right sublist recursively using merge sort*/
merge(arr,temp,low,mid,mid+1,up);/*Merge the two sorted sublists*/
copy(arr,temp,low,up);/**/
}
}/*End of mergeR()*/

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
int i=low1;
int j=low2;
int k=low1;
while((i<=up1)&&(j<=up2))
{
if(arr[i]<arr[j])
{
temp[k++]=arr[i++];
}
else
{
temp[k++]=arr[j++];
}
}
/*Copy the remaining elements of left[] , if there any*/
while(i<=up1)
{
temp[k++]=arr[i++];
}
/*Copy the remaining elements of right[] , if there any*/
while(j<=up2)
{
temp[k++]=arr[j++];
}
}/*End of merge()*/

void copy(int arr[],int temp[],int low,int up)
{
int i;
for(i=low;i<=up;i++)
{
arr[i]=temp[i];
}
}/*End of copy()*/

/*
Enter the size of an array :9

Enter the elements in an array :3 5 4 6 1 8 2 7 9

The merge sort result is :1	2	3	4	5	6	7	8	9	
*/
