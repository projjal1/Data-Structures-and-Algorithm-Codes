/*This pattern matching algo matches from left to right for a substring */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char p[80]={'a','a','b','a'};
    char t[80]="abcaabaca";

    int state[4][3];    //4 denotes no of variables in substring and 3 denotes possible no of alphabets

    state[0][0]=1;
    state[0][1]=0;
    state[0][2]=0;
    state[1][0]=2;
    state[1][1]=0;
    state[1][2]=0;
    state[2][0]=2;
    state[2][1]=3;
    state[2][2]=0;
    state[3][0]=-1;
    state[3][1]=0;
    state[3][2]=0;

    int n,s,k,i,index;
    n=strlen(t);
    k=0;
    s=0;

    while(k<n && s!=-1)
    {
        if(t[k]=='a')
            i=0;
        else if(t[k]=='b')
            i=1;
        else if(t[k]=='c')   
            i=2;
        s=state[s][i];
        k+=1;
    }

    if(s==-1)
        printf("\nFound at %d",k-strlen(p));
    else    
        printf("\nNot found");
}