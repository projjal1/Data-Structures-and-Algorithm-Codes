#include <stdio.h>

int n;

void msort(int arr[], int ll,int m,int uu) 
{ 
    int i, j; 
    int n1 = m-ll+1; 
    int n2 = uu-m; 
    
    int L[n1];
    int R[n2];
    
    for (i=0;i<n1;i++)
    {
        L[i]=arr[ll+i];
    }
    for (j=0;j<n2;j++)
    {
        R[j]=arr[m+j+1];
    }

    i=0;
    j=0;
    int k=ll;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else 
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        k++;
        j++;
    }
} 

void merge(int ar[],int l,int u)
{
    int mid=(l+u)/2;
    if(l<u)
    {
        merge(ar,l,mid);
        merge(ar,mid+1,u);
        msort(ar,l,mid,u);
    }    
}

int main(void)
{
    n=8; // Length of array
    int ar[]={12,11,13,5,6,7,7,-34};
    int i=0;

    merge(ar,0,n-1);

    printf("\nSorted array is \n");

    for (i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}