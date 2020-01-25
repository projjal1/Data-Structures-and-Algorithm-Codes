//This program aims to utilize the binary search technique using c.

#include <stdio.h.>
#include <stdlib.h>

int binary_search(int ar[],int l,int u,int sc)
{
    if (l==u)
    {
        if(ar[l]==sc)
            return 1;
        else 
            return 0;
    }
    else
    {
        int mid=(l+u)/2;
        if(ar[mid]>sc)
            binary_search(ar,l,mid-1,sc);
        else if (ar[mid]<sc)
            binary_search(ar,mid+1,u,sc);
        else 
            return 1;
    }
}

int main(void)
{
    int ar[]={1,5,45,212,223,1241};
    int sc=415;
    int n=6;
    if(binary_search(ar,0,n-1,sc))
        printf("Found");
    else 
        printf("Not found");
}
