#include <iostream>
using namespace std;

#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

void findPath(int s, int v);
void Dijkstra(int s);
int min_temp();
void create_graph();

int n;/*Number of vertices in the graph*/
int adj[MAX][MAX];
int pred[MAX];
int pathlength[MAX];
int status[MAX];

int main() 
{
int s, v;
create_graph();
cout<<"\nEnter the source vertex: ";
cin>>s;
Dijkstra(s);
while(1){
cout<<"\nEnter destination vertex (-1 to quit): ";
cin>>v;
if (v==-1)
break;
if (v<0 || v>= n)
cout<< "\nThis vertex does not exist";
else if(v==s)
cout<<"\nSource and destination vertices are the same";
else if (pathlength[v]==infinity)
cout<<"\nThere is no path from source to destination vertex";
else
findPath(s,v);
}
return 0;
}/*End of main()*/

void Dijkstra(int s) 
{
int i, current;
/*Make all vertices temporary*/
for (i=0;i<n;i++) 
{
pred[i]=NIL;
pathlength[i]=infinity;
status[i]=TEMP;
}
/*Make pathlength of source vertex equal to 0*/
pathlength[s]=0;
/*Search for the temporary vertex with minimum pathlength and make it current vertex*/
while (1) 
{
current=min_temp();
if (current==NIL)
return;
status[current]=PERM;
for (i=0; i<n;i++) 
{
/*Check for the adjacent temporary vertices*/
if ((adj[current][i] !=0) && (status[i]==TEMP))
if (pathlength[current]+adj[current][i]<pathlength[i])
{
pred[i]=current;/*Relabel*/
pathlength[i]=pathlength[current]+adj[current][i];
}
}
}
}/*End of Dijkstra()*/ 

/*Returns the temporary vertex with minimum value of pathlength*/
/*Returns NIL if no temporary vertex left or all temporary vertices left have pathlength infinity*/
int min_temp() 
{
int i;
int min=infinity;
int k=NIL;
for(i=0; i<n; i++) 
{
if (status[i]==TEMP && pathlength[i]<min) 
{
min=pathlength[i];
k = i;
}
}
return k;
}/*End of min_temp()*/ 

void findPath(int s, int v) 
{
int i, u;
int path[MAX];/*Stores the shortest path*/ 
int shortDist = 0;/*Stores the length of shortest path*/
int count = 0;/*Number of vertices in the shortest path*/ 
/*Stores the full path in the array path*/
while (v!= s) 
{
count++;
path[count]=v;
u=pred[v];
shortDist += adj[u][v];
v=u;
}
count++;
path[count]=s;
cout<<"\nShortest path is: ";
for (i=count; i>=1;i--)
cout<<path[i]<<" ";
cout<<"\nThe shortest distance is: "<<shortDist<< endl;
}/*End of findpath()*/
 
void create_graph() 
{
int i, max_edges, origin, destin, wt;
cout<<"\nEnter the number of vertices: ";
cin>>n;
max_edges=n*(n - 1);
for (i =1; i<=max_edges;i++) 
{
cout<<"\nEnter edge "<< i <<"(enter -1 -1 to finish): ";
cin>>origin>>destin;
if(origin==-1 && destin==-1)
break;
cout<<"\nEnter weight of this edge: ";
cin>>wt;

if(origin>n || destin>n || origin<0 || destin<0) 
{
cout<<"\nInvalid edge! Please enter again." << endl;
i--;
} 
else
adj[origin][destin]=wt;
}
}/*End of create_graph*/

/*
Enter the number of vertices: 6

Enter edge 1(enter -1 -1 to finish): 0 1

Enter weight of this edge: 1

Enter edge 2(enter -1 -1 to finish): 0 2

Enter weight of this edge: 4

Enter edge 3(enter -1 -1 to finish): 1 3

Enter weight of this edge: 8

Enter edge 4(enter -1 -1 to finish): 1 4

Enter weight of this edge: 7

Enter edge 5(enter -1 -1 to finish): 2 3

Enter weight of this edge: 5

Enter edge 6(enter -1 -1 to finish): 2 5

Enter weight of this edge: 3

Enter edge 7(enter -1 -1 to finish): 3 5

Enter weight of this edge: 6

Enter edge 8(enter -1 -1 to finish): 4 5

Enter weight of this edge: 2

Enter edge 9(enter -1 -1 to finish): -1 -1

Enter the source vertex: 0

Enter destination vertex (-1 to quit): 5

Shortest path is: 0 2 5 
The shortest distance is: 7
*/

