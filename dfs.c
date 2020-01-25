//Program for DFS using C
#include<stdio.h>
#include<stdlib.h>

//Array to store visited nodes
int v[7]={0,0,0,0,0,0,0};  //7 denotes the no. of vertex

void dfs(int arr[][7],int cur)
{
    //Print the visited node
    printf("\n%d",cur+1);
    //Update visited count
    v[cur]=1;

    //Find adjacent unvisited nodes
    for(int i=0;i<7;i++)
    {
        //Check adjacency and if unvisited (0 value on v array)
        if(arr[cur][i]==1 && v[i]==0)
        {
            //Go to that vertex from current
            dfs(arr,i);
        }
    }
    //Trace back
    return;
}


int main(void)
{
    //The graph as input
    int arr[][7]={{0,1,1,0,0,0,0},{1,0,0,1,1,0,0},{1,0,0,0,1,0,0},{0,1,0,0,1,1,0},{0,1,1,1,0,1,0},{0,0,0,1,1,0,0},{0,0,0,0,0,0,0}};
    
    printf("\nVertex are of the order:");

    //We need a for-loop to iterate through all vertex individually 
    //Since, DFS cannot work for unconnected graphs
    for(int i=0;i<7;i++)
    {
        if(v[i]==0)  //If Unvisited, then only continue 
            dfs(arr,i);
    }
}