//Code for bfs in c

#include <stdio.h>
#include <stdlib.h>
#define vertex 7    //No. of vertex

//Keeps track of visited vertex
int v[vertex]={0,0,0,0,0,0};

//Queue structure
int front=-1;
int rear=-1;
int queue[vertex];  //6 is the no. of vertex in the graph

//Code for insert to queue
void insert(int val)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0; //Set initial value
    }
    else 
    {
        rear+=1;  //general condition
    }
    queue[rear]=val;
}

int delete()
{
    if (front==-1)
        return -1;

    int val=queue[front++];
    
    if(rear+1==front) //Condition for empty array structure in queue
    {
        front=rear=-1; //Initialization 
    }

    return val;
}

void bfs(int arr[][vertex],int cur)
{
    //Print the current node 
    printf("\n%d",cur+1);

    //Find adjacent vertex
    for(int i=0;i<vertex;i++)
    {
        if(arr[cur][i]==1 && v[i]==0) //Check for visited or not
        { 
            v[i]=1; //Update next vertex track of visited array
            insert(i); //Add them to queue
        }
    }

    //Now dequeue and continue with the current vertex
    int d=delete();
    if(d==-1)
        return;
    bfs(arr,d);
}

int main(void)
{
    //The graph as input
    int arr[][vertex]={{0,1,1,0,0,0,0},{1,0,0,1,1,0,0},{1,0,0,0,1,0,0},{0,1,0,0,1,1,0},{0,1,1,1,0,1,0},{0,0,0,1,1,0,0},{0,0,0,0,0,0,0}};

    printf("\nVertex are of the order:");
    int count_unconnected=0; //Keeps the track of unconnected components in the graph

    for(int i=0;i<vertex;i++)
    {
        if(v[i]==0)
        {
            count_unconnected+=1;
            v[i]=1;  //Update the visited index
            bfs(arr,i);
        }
    }

    printf("\nThe graph can be divided into %d parts.",count_unconnected);
}
