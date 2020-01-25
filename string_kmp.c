#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void compute(char *pt,int m,int lps[])
{
    int len=0;
    lps[0]=0;  //first element is always set to zero
    for(int i=1;i<m;)  //Execute till m-1
    {
        if(pt[len]==pt[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else 
            {
                len=lps[len-1];
            }
        }
        
    }
}

void kmp(char *txt,char *pt)
{
    int m=strlen(pt);
    int n=strlen(txt);

    int lps[m];  //lower postion pivot and suffix array
    compute(pt,m,lps);

    //Print the lps array
    printf("\nLps array\n");
    for(int i=0;i<m;i++)
        printf("%d ",lps[i]);
    printf("\n");

    //Now we will find index of pattern in text
    int i=0;  //index of text
    int j=0;    //index of pattern

    for(;i<n;)
    {
        if(pt[j]==txt[i])
        {
            j++;
            i++;
            if(j==m-1)
            {
                printf("\nPattern found at index %d",(i-j));
                j=lps[j-1];
            }
        }
        
        else
        {
            if(j==0)
            {
                i++;
            }
            else 
            {
                j=lps[j-1];
            }
        }        
    }     
}



int main(void)
{
    char txt[]="bacbababacaab";
    char pt[]="ababaca"; 
    kmp(txt,pt);
}