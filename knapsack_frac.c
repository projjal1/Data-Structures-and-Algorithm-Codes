//Fractional Knapsack Greedy

#include <stdlib.h>
#include <stdio.h>

void knapsack(int p[],int w[],int n,int cap)
{
    int index=0;
    float sum=0;

    for(;index<n;index++)
    {
        if(cap<w[index])
            break;
        else 
        {
            sum+=p[index];
            cap-=w[index];
        }
    }

    if(index!=n)
    {
        sum+=p[index]*cap/w[index];
    }

    printf("The knapsack value is %f",sum);
}

void sort(int p[],int w[],int n)
{
    float r[n];
    //Create p/w ratio
    for(int i=0;i<n;i++)
    {
        r[i]=p[i]/w[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(r[j]<r[j+1])
            {
                float tmp1;
                int tmp2;
                
                tmp1=r[j];
                r[j]=r[j+1];
                r[j+1]=tmp1;

                tmp2=p[j];
                p[j]=p[j+1];
                p[j+1]=tmp2;

                tmp2=w[j];
                w[j]=w[j+1];
                w[j+1]=tmp2;
            }
        }
    }
}

int main(void)
{
    int n;
    printf("\nEnter the no. of elements: ");
    scanf("%d",&n);

    int p[n],w[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter the value and weight of %d element: ",i+1);
        scanf("%d %d",&p[i],&w[i]);
    }

    sort(p,w,n);

    for(int i=0;i<n;i++)
        printf("%d %d ; ",p[i],w[i]);

    int cap;

    printf("\nEnter the capacity: ");
    scanf("%d",&cap);

    knapsack(p,w,n,cap);
}