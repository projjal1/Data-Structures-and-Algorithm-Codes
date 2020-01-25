#include <stdio.h>
#include <stdlib.h>

void sort(int ar[],int left,int right)
{   
    int pivot;
    if(left<right)
    {
        pivot=partition(ar,left,right);
        sort(ar,left,pivot-1);
        sort(ar,pivot+1,right);
    }
}

int partition(int ar[],int i,int j)
{
    int pivot=ar[i];
    int index=i;
    while(i<j)
    {
        while(pivot<ar[j])
        {
            j--;
        }
        while(pivot>=ar[i])
        {
            i++;
        }
        if(i<j)
        {
            int tmp=ar[i];
            ar[i]=ar[j];
            ar[j]=tmp;
        }
    }
    int tmp=ar[j];
    ar[j]=ar[index];
    ar[index]=tmp;
    return j;
}

int main(void)
{
    int ar[]={546,-1,-2,12,10,80,30,90,1,89,-4,50,70};
    int left=0;
    int right=(int)(sizeof(ar)/sizeof(int)) -1;

    sort(ar,left,right);

    printf("\nSorted array\n");
    int i=0;
    for (;i<=right;i++)
    {
        printf("%d ",ar[i]);
    }
}