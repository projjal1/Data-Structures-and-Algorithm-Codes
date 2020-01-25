#include <stdio.h>
#include <stdlib.h>

int x[100];
int sol_count=0;

int place(int k,int i)
{
    int j=0;
    for(;j<=k-1;j++)  //Check for previous rows 
    {
        if(i==x[j]) //Checks for same column 
            return 0;
        if(abs(x[j]-i)==abs(j-k)) //Checks for lower  and upper diagonal
            return 0;
    }
    return 1;
}

void nqueens(int k,int n)
{
    for(int i=0;i<n;i++) //Checking for each column of a row
    {
        if(place(k,i)==1)
        {
            x[k]=i;  //Adding that row

            if(k==n-1)
            {
                sol_count+=1;
                //Let's print the columns for each row
                printf("\nPostions of queens:- ");
                for(int l=0;l<n;l++)
                {
                    printf("\n%d , %d ",l+1,(x[l]+1));
                }
            }
            else
            {
                nqueens(k+1,n);                
            }            
        }
    }
    return ;

}
int main(void)
{
    int k;
    k=0;  //Starting row
    int n;  //No. of queens

    printf("\nEnter the no. of queens:");
    scanf("%d",&n);

    for (int i=0;i<n;i++)   
        x[i]=0;

    nqueens(k,n);

    printf("\n\nThe no. of solutions obtained is %d",sol_count);

    return 0;
}