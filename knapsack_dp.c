#include<stdlib.h>
#include<stdio.h>

int max(int a,int b)
{
    int m=(a>b)?a:b;
    return m;
}

int knap(int n,int v[],int w[],int cap)
{
    int val[n+1][cap+1];
    for(int j=0;j<=cap;j++)
        val[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(w[i]<=j)
                val[i][j]=max(val[i-1][j],(v[i]+val[i-1][j-w[i]]));
            else 
                val[i][j]=val[i-1][j];
        }
    }
    return val[n][cap];
}

int main()
{
    int n=3;
    int v[3]={60,100,120};
    int w[3]={10,20,30};
    int cap=50;

    int res=knap(n,v,w,cap);
    printf("The result is %d",res);

    return 0;
}