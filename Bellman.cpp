#include<iostream>
using namespace std;
#define MAX 100
#define infinity 9999
#define NIL -1
#define TRUE 1
#define FALSE 0
int n;/*Number of vertices in the graph*/
int adj[MAX][MAX];
int predecessor[MAX];
int pathLength[MAX];
int isPresent_in_queue[MAX];
int front,rear;
int queue[MAX];
void initilize_queue();
void insert_queue(int u);
int delete_queue();
int isEmpty_queue();
void create_graph();
void findPath(int s, int v);
int BellmanFord(int s);

int main()
{
int flag,s,v;
create_graph();
cout<<"\nEnter the source vertex :";
cin>>s;
flag = BellmanFord(s);
if(flag==-1)
{
cout<<"\nError: Negative cycle in graph\n";
exit(1);
}
while(1)
{
cout<<" \nEnter the destination vertex(-1 to quit):";
cin>>v;
if(v==-1)
break;
if(v<0 || v>=n)
cout<<"\nThis vertex does not exist\n";
else if(v==s)
cout<<"\nSource and destination vertex are same\n";
else if(pathLength[v]==infinity)
cout<<"\nThere is no path from source to destination vertex\n";
else
findPath(s,v);
}
}/*End of main()*/

void findPath(int s, int v)
{
int i,u;
int path[MAX];/*Stores the shortest path*/
int shortdist = 0;/*Stores the length of shortest path*/
int count = 0;/*Number of vertices in the shortest path*/
/*Store the full path in the array path*/
while(v!=s)
{
count++;
path[count]= v;
u = predecessor[v];
shortdist += adj[u][v];
v=u;
}
count++;
path[count]=s;
cout<<"\nShortest path is :";
for(i=count;i>=1;i--)
cout<<""<<path[i];
cout<<"\nShortest distance is :"<<shortdist;
}/*End of findpath()*/

int BellmanFord(int s)
{
int k=0,i,current;
for(i=0;i<n;i++)
{
predecessor[i]= NIL;
pathLength[i]= infinity;
isPresent_in_queue[i] = FALSE;
}
initilize_queue();
pathLength[s]= 0;/*Make pathlength of source vertex 0*/
insert_queue(s);/*Insert the source vertex in the queue*/
isPresent_in_queue[s] = TRUE;
while(!isEmpty_queue())
{
current= delete_queue();
isPresent_in_queue[current] = FALSE;
if(s==current)
k++;
if(k>n)
return -1;/*Negative cycle reachable from source vertex*/
for(i=0;i<n;i++)
{
if(adj[current][i]!=0)
if(pathLength[i]>pathLength[current]+adj[current][i])
{
pathLength [i]=pathLength[current]+adj[current][i];
predecessor[i]=current;
if(!isPresent_in_queue[i])
{
insert_queue(i);
isPresent_in_queue[i]= TRUE;
}
}
}
}
return 1;
}/*End of BellmanFord()*/

void initialize_queue()
{
int i;
for(i=0;i<MAX;i++)
queue[i]= 0;
rear= -1; front= -1;
}/*End of initialize_queue()*/

int isEmpty_queue()
{
if(front==-1||front>rear)
return 1;
else
return 0;
}/*End of isEmpty_queue()*/

void insert_queue(int added_item)
{
if(rear==MAX-1)
{
cout<<"Queue is overflow\n";
exit(1);
}
else
{
if(front==-1)
front = 0;
rear = rear+1;
queue[rear]= added_item;
}
}/*End of insert_queue()*/

int delete_queue()
{
int d;
if(front==-1||front>rear)
{
cout<<"Queue is underflow\n";
exit(1);
}
else
{
d= queue[front];
front = front+1;
}
return d;
}/*End of delete_queue()*/

void create_graph()
{
int i,max_edges,origin,destin,wt;
cout<<"\nEnter number of vertices :";
cin>>n;
max_edges=n*(n-1);
for(i=1;i<max_edges;i++)
{
cout<<"\nEnter edge (-1-1 to quit) :";
cin>>origin>>destin;
if((origin==-1)&&(destin==-1))
break;
cout<<"\nEnter weight for this edge :";
cin>>wt;
if(origin>=n||destin>=n||origin<0||destin<0)
{
cout<<"\nInvalid edge!";
i--;
}
else
adj[origin][destin]=wt;
}
}/*End of create_graph()*/

/*
Enter number of vertices :5

Enter edge (-1-1 to quit) :0 1

Enter weight for this edge :1

Enter edge (-1-1 to quit) :0 3

Enter weight for this edge :8

Enter edge (-1-1 to quit) :0 4

Enter weight for this edge :6

Enter edge (-1-1 to quit) :1 2

Enter weight for this edge :-4

Enter edge (-1-1 to quit) :1 3

Enter weight for this edge :3

Enter edge (-1-1 to quit) :2 4

Enter weight for this edge :9

Enter edge (-1-1 to quit) :3 4

Enter weight for this edge :-2

Enter edge (-1-1 to quit) :-1 -1

Enter the source vertex :0
 
Enter the destination vertex(-1 to quit):4

Shortest path is :0134
Shortest distance is :2 
*/
