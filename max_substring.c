//Divide and conquer technique to find max subarray

#include <stdio.h>
#include <limits.h>

int maximum(int a,int b,int c)
{
    if(a>=b && a>=c)
        return a;
    else if(b>c)
        return b;
    else 
        return c;
}

int max_sum(int ar[],int a,int b,int c)
{
    int lsum,rsum,sum;
    lsum=rsum=INT_MIN;
    sum=0;
    int i=0;
    for(i=b;i>=a;i--)
    {
        sum+=ar[i];
        if(sum>lsum)
        {
            lsum=sum;
        }
    }
    sum=0;
    for(i=b+1;i<=c;i++)
    {
        sum+=ar[i];
        if(sum>rsum)
        {
            rsum=sum;
        }
    }
    return (lsum+rsum);
}

int partition(int ar[],int l,int u)
{
    int left_array,right_array,max_array;
    int mid;
    if(l==u)
    {
        return ar[l];
    }
    if(l<u)
    {
        mid=(l+u)/2;
        left_array=partition(ar,l,mid);
        right_array=partition(ar,mid+1,u);
        max_array=max_sum(ar,l,mid,u);
    }
    return maximum(left_array,right_array,max_array);
}

int main()
{
    int ar[]={3,-1,-1,10,-3,-2,4};  //Given array
    //Now if the array had all non-negative nos then array would be the max subarray
    //Else we need to find it
    int size=sizeof(ar)/sizeof(int);

    printf("Max of sub-array sum is %d and indexes are %d,%d",partition(ar,0,size-1),globalx,globaly);
    return 0;
}