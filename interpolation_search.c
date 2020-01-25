//Program to demonstrate interpolation search in C.

#include<stdio.h>

void interpolate(int ar[],int l,int h,int sc)
{
    int iter=1; //Keeps track of no. of iterations
    while(l<h && sc>=ar[l] && sc<=ar[h])
    {
        int pos = l+((sc-ar[l])*(h-l)/(ar[h]-ar[l]));
        printf("\nIteration %d",iter);
        if(sc=ar[pos])
        {
            printf("\nFound at index %d",pos);       
            return ; 
        }
        else if (sc<ar[pos])
        {
            h=pos-1;
        }
        else 
            l=pos+1;
    }
    printf("Not found");
}
int main(void)
{
    int ar[]={10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
    int n=sizeof(ar)/sizeof(int);
    int sc=19;
    interpolate(ar,0,n-1,sc);
}