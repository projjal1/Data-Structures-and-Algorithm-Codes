//Single source shortest path djisktra

#include <stdio.h>
#include <stdlib.h>

int cost[6][6]={{0,2,4,0,0,0},{0,0,1,7,0,0},{0,0,0,0,3,0},{0,0,0,0,2,1},{0,0,0,0,5,0},{0,0,0,0,0,0}};
int node[6]={0,9999,9999,9999,9999,9999};

void compute(int n,int src,int dest)
{
    if(src==dest)
        return;

    int j=0;

    for(j=src;j<n;j++)
    {
        if(j==src)
            continue;
        if(cost[src][j]!=0)
        {
            int s=cost[src][j]+node[src];
            if(s<node[j])  //Perform relaxation
            {
                node[j]=s;
            }
        }
        compute(n,j,dest);
    }

}

int main(void)
{
    /*int n;
    printf("Enter the no. of vertex: ");
    scanf("%d",&n);

    int i=1;
    int j=1;

    //If no path exists enter 0
    for(;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\nWeight for %d to %d :",i,j);
            scanf("%d",&cost[i-1][j-1]);
        }
    }

    int src,dest;
    printf("\nEnter the source node: ");
    scanf("%d",&src);
    printf("\nEnter the destination node: ");
    scanf("%d",&dest);

    //set source node to 0 only all others be 9999
    for(i=0;i<n;i++)
    {
        if(i==src)
            node[i]=0;
        else
            node[i]=9999;
    }*/

    int n=6;   
    
    int src=0;
    int dest=5;

    compute(n,src,dest);

    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",node[i]);
    }
}