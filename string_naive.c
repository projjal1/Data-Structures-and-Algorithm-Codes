#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void naive(char *txt,char *pt)
{
    int m=strlen(pt);
    int n=strlen(txt);

    for(int i=0;i<=(n-m);i++)
    {
        int j=0;
        for(;j<m;j++)
        {
            if(pt[j]!=txt[i+j])
            {
                break;
            }
        }
        if(j==m)
        {
            printf("\nFound at %d",i);
        }
    }
}



int main(void)
{
    char txt[]="ABABDABACDABABCABAB";
    char pt[]="ABABCABAB"; 
    naive(txt,pt);
}