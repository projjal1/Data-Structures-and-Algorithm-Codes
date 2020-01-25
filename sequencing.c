#include <stdio.h>
#include <stdlib.h>


void swap(int ar[],int p1,int p2)
{
    int tmp=ar[p1];
    ar[p1]=ar[p2];
    ar[p2]=tmp;
}

void sort(int p[],int d[],int n)
{
    int i=0;
    int j;

    for(;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(p[j]<p[j+1])
            {
                swap(p,j,j+1);
                swap(d,j,j+1);
            }   
        }
    }

    printf("After sorting :- \n");
    int i=0;
    for(;i<n;i++)
    {
        printf("\n %d %d",p[i],d[i]);
    }
}

void find_opt(int d[],int n)
{
    //sequence of jobs 
    int j[n];

    j[0]=0;  //Including the first job
    int k=0;  //Track of position of included job

    int i=0;

    for(i=1;i<n;i++)  //Starting from second job
    {
        int r=k;

        while(d[j[r]]>d[i]  && (d[j[r]]!=r))
            r--;
    }
}