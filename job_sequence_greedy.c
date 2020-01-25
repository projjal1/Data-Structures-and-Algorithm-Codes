#include <stdio.h>
#include<stdlib.h>

int job(int p[],int d[],int n)
{
    int j[50];
    j[0]=0;
    d[0]=0;

    j[1]=1; //Inclusion of the first job
    int k=1;

    for(int i=2;i<n;i++)
    {
        int r=k;
        while((d[j[r]]>d[i]) && (d[j[r]]!=r))
            r=r-1;
        
        if ((d[j[r]]<=d[i]) && (d[i]>r))
        {
            for (int q=k;q>=r+1;q--)
                j[q+1]=j[q];
            j[r+1]=i;
            k=k+1;
        }
    }
    
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        printf("%d ",j[i]);
        sum+=p[j[i]];
    }

    printf("\n%d",sum);
}

int main(void)
{
    int n;
    n=7;
    int p[]={0,300,200,190,180,120,100};
    int d[]={0,2,5,3,3,4,2};

    job(p,d,n);
}
