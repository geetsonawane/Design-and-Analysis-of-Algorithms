#include<iostream>
using namespace std;

int binarySearch(int array[],int x,int low,int up)
{
if(up>=low)
{
int mid=(low+up)/2;/*Find middle element in an array*/

if(array[mid]==x)/*Compare the middle element of the search space with the key element*/
return mid;

if(array[mid]>x)
return binarySearch(array,x,low,mid-1);/*Remove all the elements from the right search space , including the middle element*/
return binarySearch(array,x,mid+1,up);/*Remove all the elements from the left search space , including the middle element*/
}
return -1;
}/*End of binarySearch()*/

int main()
{
int array[10];
int i,n;
cout<<"Enter the size of an array :";
cin>>n;
cout<<"\nEnter the elements in an array:";
for(i=0;i<n;i++)
{
cin>>array[i];
}
int x;
cout<<"\nEnter the element you want to search :";
cin>>x;
int result=binarySearch(array,x,0,n-1);
if(result==-1)
cout<<"\nThe element is not found";
else
cout<<"\nThe element is found at index :"<<result;
return 0;
}/*End of main()*/

/*
Enter the size of an array :9

Enter the elements in an array:1 2 3 4 5 6 7 8 9

Enter the element you want to search :5

The element is found at index :4
*/
