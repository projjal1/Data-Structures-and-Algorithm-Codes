#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int n=4;  //no. of matrix
int graph[4][4]; //cost matrix
bool v[4]; //visited
int ans=INT_MAX;

int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}

void tsp(int currPos,int n,int count,int cost)
{
    if(count==n && graph[currPos][0])
    {
        ans=min(ans,cost+graph[currPos][0]);
        return ;
    }

    for(int i=0;i<n;i++)
    {
        if(!v[i] && graph[currPos][i])
        {
            v[i]=true;
            return tsp(i,n,count+1,cost+graph[currPos][i]);
            v[i]=false;
        }
    }
}

int main()
{
    int i,j;
    v[0]=v[1]=v[2]=v[3]=false;
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\nEnter element: ");
            scanf("%d",&graph[i][j]);
        }
    }
    v[0]=true;
    tsp(0,n,1,0);
    printf("%d",ans);
}