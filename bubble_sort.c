#include <stdio.h>

int sort(int ar[],int n)
{
    int i=0;
    int j=0;
    int temp;

    for(;i<n;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(ar[j]>ar[j+1])  //Ascending order
            {
                temp =ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp;
            }
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