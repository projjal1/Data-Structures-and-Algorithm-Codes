//Using lomuto algo for randomized pivot quick sort

#include <stdio.h>
#include <stdlib.h>

void swap(int a,int b,int ar[])
{
    int tmp=ar[a];
    ar[a]=ar[b];
    ar[b]=tmp;
}
int partition(int ar[],int i,int j)
{
    int index=i;
    int pivot=ar[index];
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
            swap(i,j,ar);
        }
    }
    swap(index,j,ar);
    return j;
}

int random_pivot(int ar[],int left,int right)  //Choose a random pivot and swap with lowest bound 
{
    int gap=(right-left+1);  //Length of subarray
    int r=left+rand()%gap;
    swap(left,r,ar);
    return partition(ar,left,right);
}

void sort(int ar[],int left,int right)
{   
    int pivot;
    if(left<right)
    {
        pivot=random_pivot(ar,left,right);
        sort(ar,left,pivot-1);
        sort(ar,pivot+1,right);
    }
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