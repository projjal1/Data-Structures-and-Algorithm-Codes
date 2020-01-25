/*This pattern matching algo matches from left to right for a substring */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char p[80]={'b','a','b'};
    char t[80]="aabbbcabb";

    int r,s,k,l,max,index;

    r=strlen(p);
    s=strlen(t);
    max=s-r;
    l=0;

    k=0; //Acts almost as a loop and index variable.

    while(k<=max)
    {
        for (l=0;l<r;l++)
        {
            if(p[l]!=t[k+l])
                break;
        }
        if(l==r)
        {
            index=k;
            break;
        }
        else
        {
            k+=1;
        }
    }
    if(k>max)
    {
        index=-1;
    }

    if(index!=-1)
        printf("Found at index %d ",k);
    else    
        printf("Substring not found");

}