#include <stdio.h>
#include <limits.h>

int compute(int ar[],int n)
{
    int m[n][n];
    int i=0;
    for(i=0;i<n;i++)
    {
        m[i][i]=0;  //Cost of multiplying a matrix to itself is 0
    }

    //We have chosen a zero row and zero column redundant 
    int l,j,k;
    int q;
    for(l=2;l<n;l++)  //No of matrix we are multiplying at a time
    {
        for(i=1;i<n-l+1;i++)  //Row variable loop
        {
            j=i+l-1;  //Limit of column reached upto at a time
            m[i][j]=INT_MAX;  //Keeping target cell set to max no. to find the minimum
            for (k=i;k<j;k++)  //Column variable loop
            {
                q=m[i][k]+m[k+1][j]+ar[i-1]*ar[k]*ar[j];
                if(q<m[i][j]) //setting least no. of operation
                {
                    m[i][j]=q;
                }
            }
        }
    }
    return m[1][n-1];
}

int main(void){
    int n;
    printf("\nEnter the no of arrays :- ");
    scanf("%d",&n);
    int ar[n+1];
    int i=0;
    for(;i<n+1;i++)
    {
        printf("Enter dimension: ");
        scanf("%d",&ar[i]);
    }
    printf("\nThe required minimum no. of multiplication operations %d",compute(ar,n+1));
}