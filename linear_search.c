#include <stdio.h>

int search(int ar[],int n,int sc)
{
    int i=0;
    while(i<n)
    {
        if(ar[i]==sc)
            return (i+1);
        else 
            continue;
    }
    return -1;
}

int main(void)
{
    int n,s;
    
    printf("\nEnter the size of array :-  ");
    scanf("%d",&n);

    int ar[n];  //Declaring array
    int i=0;

    for (;i<n;i++)
    {
        printf("\nEnter the array element :-  ");
        scanf("%d",&ar[i]);
    }

    printf("\nEnter the search element :-  ");
    scanf("%d",&s);

    int res=search(ar,n,s);
    if(res!=-1)
        printf("\nFound at index %d",res);
    else 
        printf("\nNot found");
}