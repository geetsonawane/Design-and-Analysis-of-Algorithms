#include<iostream>
using namespace std;


#define infinity 99999
#define max 100
int n; /*Number of vertices in the graph*/
int adj[max][max]; /*Weighted adjacency matrix*/
int D[max][max]; /*Shortest path matrix*/
int pre[max][max]; /*Predecessor matrix*/

void create_graph();
void warshall();
void find_path(int s,int d);
void display(int mat[max][max],int n);

int main()
{
int s,d;
create_graph();
warshall();
while(1)
{
cout<<"\nEnter the source(-1) to exit: ";
cin>>s;
if(s==-1)
break;
cout<<"\nEnter destinaton vertex: ";
cin>>d;
if(s<0 || s>n-1||d<0 ||d>n-1)
{
cout<<"Enter a valid vertex\n";
continue;
}
cout<<"\nShortest path is :";
find_path(s,d);
cout<<"\nLength of path is "<<D[s][d];
return 0;
}
} /*End of main()*/

void create_graph()
{
int i,max_edges,origin,destin,wt;
cout<<"\nEnter the number of vertices: ";
cin>>n;
max_edges=n*(n-1);
for(i=1;i<=max_edges;i++)
{
cout<<"\nEnter the edge (-1 -1 to quit) "<<i<<":";
cin>>origin>>destin;
if((origin==-1)&&(destin==-1))
break;
cout<<"\nEnter the weight for this edge :";
cin>>wt;
if(origin>=n||destin>=n||origin<0||destin<0)
{
cout<<"\nInvalid edge !";
i--;
}
else
{
adj[origin][destin]=wt;
}
}
} /*End of create_graph()*/

void warshall()
{
int i,j,k;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if(adj[i][j]==0)
{
D[i][j]=infinity;
pre[i][j]=-1;
}
else
{
D[i][j]=adj[i][j];
pre[i][j]=i;
}
}
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(D[i][k]+D[k][j] <D[i][j])
{
D[i][j]=D[i][k]+D[k][j];
pre[i][j]=pre[k][j];
}
}
cout<<"\nShortest path matrix is :\n";
display(D,n);
cout<<"\nPredecessor matrix is :\n";
display(pre,n);
} /*End of warshall()*/

void find_path(int s,int d)
{
int i;
int path[max];
int count ;
if(D[s][d]==infinity)
{
cout<<"\nNo path found";
return;
}
count=-1;
do
{
path[++count]=d;
d=pre[s][d];
}
while(d!=s);
path[++count]=s;
for(i=count ;i>=0;i--)
cout<<path[i]<<" ";
cout<<"\n";
} /*End of find_path()*/

void display(int mat[max][max],int n)
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
cout<<mat[i][j]<<" ";
cout<<"\n";
}
} /*End of display()*/

/*Enter the number of vertices : 4

Enter the edge (-1 -1 to quit) 1 : 0 1

Enter the weight for this edge : 2

Enter the edge (-1 -1 to quit) 2 : 0 3

Enter the weight for this edge : 9

Enter the edge (-1 -1 to quit) 3 : 1 0

Enter the weight for this edge : 3

Enter the edge (-1 -1 to quit) 4 : 1 2

Enter the weight for this edge : 4

Enter the edge (-1 -1 to quit) 5 : 1 3

Enter the weight for this edge : 7

Enter the edge (-1 -1 to quit) 6 : 2 1

Enter the weight for this edge : 6 

Enter the edge (-1 -1 to quit) 7 : 2 3

Enter the weight for this edge : 2

Enter the edge (-1 -1 to quit) 8 : 3 0

Enter the weight for this edge : 14

Enter the edge (-1 -1 to quit) 9 : 3 2

Enter the weight for this edge : 4 

Enter the edge (-1 -1 to quit) 10 : -1 -1

Shortest path matrix is :
5 2 6 8
3 5 4 6
9 6 6 2
13 10 4 6

Predecessor matrix is :
1 0 1 2
1 0 1 2
1 2 3 2
1 2 3 2

Enter the source (-1 ) to exit : 3

Enter destination vertex : 0

Shortest path is : 3 2 1 0
*/