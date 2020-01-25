#include<stdio.h>
#include<stdlib.h>

int g[10][10];
int solution_count=0;
int m;  //No. of colors with which to be tested

void nextvalue(int k,int n,int x[])
{
    while(1) //Continue with another color
    {
        int value=0;  //Allocating a color to kth vertex
        value=(x[k]+1)%(m+1);
        x[k]=value;

        if(value==0)
            return;  //No color is allocated(space is full)
        
        int j=0;
        for(;j<n;j++)
        {
            if(g[k][j]!=0  && (x[k]==x[j]))  //Check if adjacency exist and then if same color is assigned to them
                break;
        }
        if(j==n)
            return;  //Color is assigned
    }
}

void mcolor(int k,int n,int x[])
{
    while(1)
    {
        nextvalue(k,n,x);
        if(x[k]==0)  //No more colors can be allocated
            return ;
        if (k==n-1)  //All vertices have been assigned colors
        {
            solution_count+=1;
            for(int i=0;i<n;i++)
            {
                printf("%d ",x[i]);
            }
            printf("\n");
            return;
        }
        else 
        {
            mcolor(k+1,n,x);
        }
    }
}

int main(void)
{
    int k=0;

    int n;
    printf("\nEnter the no. of vertex : ");
    scanf("%d",&n);

    int x[n];
    for(int i=0;i<n;i++)
        x[i]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter value for [%d,%d]",i,j);
            scanf("%d",&g[i][j]);
        }
    }

    printf("\nEnter the no. of colors to be used : ");
    scanf("%d",&m);

    mcolor(k,n,x);

    if(solution_count>0)
        printf("\nThe no. of solutions is: %d",solution_count);
    else
        printf("\nNo. solutions exist with %d colors",m);
}

