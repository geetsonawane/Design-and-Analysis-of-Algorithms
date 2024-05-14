#include<iostream>
using namespace std;

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;/*Number of vertices in the graph*/
int adj[MAX][MAX];
int state[MAX];/*It can be initial , waiting or visited*/
int queue[MAX],front=-1,rear=-1;

void create_graph();
void BF_traversal();
void bfs(int v);
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main() 
{
create_graph();
BF_traversal();
return 0;
}/*End of main()*/

void create_graph() 
{
int i,max_edges,origin,destin;
cout<<"\nEnter the number of vertices: ";
cin>> n;
max_edges=n*(n - 1);
for(i=0;i<max_edges;i++) 
{
cout<<"\nEnter the edge(-1 -1 to quit): ";
cin>>origin>>destin;
if((origin==-1)&&(destin == -1))
break;
adj[origin][destin]=1; 
}
}/*End of create_graph()*/

void BF_traversal() 
{
int v;
cout<<"\nEnter starting vertex for breadth-first search: ";
cin>>v;
for(int i=0;i<n;i++)
state[i]=initial;/*Initially all vertices are at initial state*/
bfs(v);
}/*End of BF_Traversal*/

void bfs(int v) 
{
int i;
insert_queue(v);/*Insert the starting vertex into the queue*/
state[v]=waiting;/*Change the state of starting vertex from initial to waiting*/
while(!isEmpty_queue()) 
{
v=delete_queue();/*Delete front element from the queue*/
cout<<v<<" ";/*Visit the starting vertex */
state[v]=visited;/*Change the state of starting vertex from waiting to visited*/
for(i=0;i<n;i++) 
{
/*Check for adjacent unvisited vertices*/
if(adj[v][i]==1&&state[i]==initial) 
{
insert_queue(i);
state[i]=waiting;/*Change the state of all vertices from initial to waiting*/
}
}
}
cout<<endl;
}/*End of bfs()*/

void insert_queue(int vertex) 
{
if(rear==MAX-1)
cout<<"\nQueue is overflow:";
else 
{
if(front==-1)/*If queue is initially empty*/
front=0;
rear=rear+1;
queue[rear]=vertex;
}
}/*End of insert_queue()*/

int isEmpty_queue() 
{
if(front==-1||front > rear)
return 1;
else
return 0;
}/*End of isEmpty_queue()*/

int delete_queue() 
{
int del_item;
if(front==-1||front>rear)
{
cout<<"\nQueue is underflow:";
exit(1);
}
del_item=queue[front];
front=front+1;
return del_item;
}/*End of delete_queue()*/

/*
Enter the number of vertices: 9

Enter the edge(-1 -1 to quit): 0 1

Enter the edge(-1 -1 to quit): 0 3

Enter the edge(-1 -1 to quit): 0 4

Enter the edge(-1 -1 to quit): 1 2

Enter the edge(-1 -1 to quit): 1 4

Enter the edge(-1 -1 to quit): 3 4

Enter the edge(-1 -1 to quit): 3 6

Enter the edge(-1 -1 to quit): 4 5

Enter the edge(-1 -1 to quit): 4 7

Enter the edge(-1 -1 to quit): 6 4

Enter the edge(-1 -1 to quit): 6 7

Enter the edge(-1 -1 to quit): 7 5

Enter the edge(-1 -1 to quit): 7 8

Enter the edge(-1 -1 to quit): -1 -1

Enter starting vertex for breadth-first search: 0
0 1 3 4 2 6 5 7 8 
*/
