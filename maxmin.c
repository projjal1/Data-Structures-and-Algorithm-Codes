#include <stdlib.h>
#include <stdio.h>

void maxmin(int *a,int l,int u,int *min,int *max)
{
    int lmax,lmin,rmax,rmin,mid;
    //As array has one element then min and max is equal
    if(l==u)
    {
        *max=a[l];
        *min=a[u];
    }
    //We compare both the elements
    else if(u==l+1)
    {
        if(a[l]<a[u])
        {
            *max=a[u];
            *min=a[l];
        }
        else 
        {
            *max=a[l];
            *min=a[u];
        }
    }
    else 
    {
        mid=(l+u)/2;
        //Dividing the array into two subparts
        maxmin(a,l,mid,&lmin,&lmax);
        maxmin(a,mid+1,u,&rmin,&rmax);
        //Now comparing max and min of each left and right subarrays
        *min=(lmin>rmin)?rmin:lmin;
        *max=(lmax>rmax)?lmax:rmax;
    }
}
int main()
{
    int n=10;
    int max,min;
    int ar[n];
    //Allowing the array to take random arbitary elements
    for (int i=0;i<10;i++)
    {
        ar[i]=rand();
    }
    //Call to max min function
    maxmin(ar,0,n-1,&min,&max);
    //Printing the max and min
    printf("Max is %d and min is %d",max,min);
}