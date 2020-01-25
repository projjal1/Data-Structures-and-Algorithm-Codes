#include <stdio.h>

int search(int ar[],int up,int low,int sc)
{
    int mid=0;
    int mid_ele=0;

    while(low<up)
    {
        mid=(up+low)/2;
        mid_ele=ar[mid];
        if(sc<mid_ele)
            up--;
        else if (sc>mid_ele)
            low++;
        else 
        {
            return (mid+1);
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int ar[n];

    int i=0;

    for(;i<n;i++)
    {
        printf("\nEnter the array element %d  :   ",(i+1));
        scanf("%d",&ar[i]);
    }

    int s;
    printf("Enter the search element: ");
    scanf("%d",&s);

    int res=search(ar,n-1,0,s);

    if(res!=-1)
        printf("\nFound at index : =  %d",res);
    else 
        printf("\nNot found");
}