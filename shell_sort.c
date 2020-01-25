#include<stdio.h>
#include<stdlib.h>

void sort(int ar[],int n)
{
    unsigned int i=0;
    unsigned int j=0;
    unsigned int gap=0;
    for (gap=n/2;gap>0;gap/=2)
    {
        for (i=gap;i<n;i++)
        {
            int temp=ar[i];
            for (j=i;j>0;j=j-gap)
            {
                if(ar[j-gap]>temp)
                {
                    ar[j]=ar[j-gap];
                }
                else 
                    break;
            }
            ar[j]=temp;
        }
    } 
}

int main(void)
{
    int n;
    int ar[]={45,13,-1,90,12};
    n=(int)(sizeof(ar)/sizeof(int));

    sort(ar,n);
    
    int i=0;
    printf("\nSorted array:- \n");
    for (;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}