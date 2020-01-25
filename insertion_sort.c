#include <stdio.h>

int sort(int ar[],int n)
{
    int i=1;
    int j=0;
    int temp_ele=0;

    for(;i<n;i++)
    {
        temp_ele=ar[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp_ele<ar[j])
            {
                ar[j+1]=ar[j];
                continue;
            }
            else
            {
                break; 
            }
        }
        ar[j+1]=temp_ele;
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