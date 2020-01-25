#include <stdio.h>

int a[8][8]={{999,999,999,999,999,999,999,999},
            {999,999,28,999,999,999,10,999},
            {999,28,999,16,999,999,999,14},
            {999,999,16,999,12,999,999,999},
            {999,999,999,12,999,999,999,18},
            {999,999,999,999,22,999,25,24},
            {999,10,999,999,999,25,999,999},
            {999,999,14,999,18,24,999,999}};

int k,l;


void find_min_edge()
{
    int i=1;
    int j=1;
    int min=999;
    for(;i<8;i++)
    {
        for(j=1;j<8;j++)
        {
            if(min>a[i][j])
            {
                min=a[i][j];
                k=i;
                l=j;
            }
        }
    }
}

int prims()
{
    int near[8]; //Initialization of near value
    find_min_edge();
    
    int t[8][3];  //Keeps record of the edges taken.

    int min_cost=a[k][l];  //Initialization of cost func.
    
    int i=0;
    //Initialize near to check if vertex already counted or not
    for(i=1;i<8;i++)
    {
        if(a[i][l]<a[i][k])
        {
            near[i]=l;
        }
        else 
            near[i]=k;
    }

    t[1][1]=k;
    t[1][2]=l;

    near[l]=near[k]=0;  //Since l and  k vertex have already been counted.

    for(i=2;i<7;i++)
    {
        //Find closest value of j such that near[j]!=0 and j,near[j] has minimum cost
        int min=999;
        int min_vertex=0;
        int j=0;
        for(j=1;j<8;j++)
        {
            if(near[j]!=0 && a[j][near[j]]<min)
            {
                min=a[j][near[j]];  //We get next closest vertex of either k or l
                min_vertex=j;  //Thus we get next closest vertex of k or l
            }
        }
        t[i][1]=near[min_vertex];
        t[i][2]=min_vertex;

        //Updating the min_cost
        min_cost+=a[near[min_vertex]][min_vertex];

        near[min_vertex]=0;  //counting it too
        
        for (j=1;j<8;j++)
        {
            if(near[j]!=0 && (a[j][near[j]]>a[j][min_vertex]))
            {
                near[j]=min_vertex;
            }
        }

    }

    for(int iter=1;iter<7;iter++)
    {
        printf("Edge : %d %d ",t[iter][1],t[iter][2]);
    }
    return min_cost;
}


int main(void)
{
    printf("\nMin Cost :- %d",prims());
}