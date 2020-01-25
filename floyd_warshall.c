//Floyd-Warshall
#include<stdio.h>
#include<stdlib.h>

int cost[3][3]={{0,4,11},{6,0,2},{3,9999,0}};

void compute(int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                int s=cost[i][k]+cost[k][j];
                if(s<cost[i][j])
                {
                    cost[i][j]=s;
                }
            }
        }
    }
}

int main(void)
{
    int n;
    n=3;
    
    compute(n);

    int i=0;
    int j=0;
    for(;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
}

