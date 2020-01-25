#include <stdio.h>

int sort(int ar[],int n)
{
    int i=0;
    int j=0;
    int temp;
    int min;
    int pos;

    for(;i<n;i++)
    {
        min=ar[i];
        pos=i;
        for(j=i;j<n;j++)
        {
            if(ar[j]<min)
            {
                pos=j;
                min=ar[j];
            }
        }
        if(pos==i)
        {
            continue;
        }
        else 
        {
            temp=ar[i];
            ar[i]=min;
            ar[pos]=temp;
        }
    }
}

int main(void)
{
    int n;
    
    printf("\nEnter the size of array :-  ");
    scanf("%d",&n);

    int ar[n];  //Declaring array
    int i=0;

    for (;i<n;i++)
    {
        printf("\nEnter the array element :-  ");
        scanf("%d",&ar[i]);
    }

    sort(ar,n);

    printf("\nPrinting sorted array\n");
    
    for (i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }    
}