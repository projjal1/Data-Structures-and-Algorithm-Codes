#include <stdio.h>

int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
    {
        gcd(b%a,a);
    }
    
}

int main(void){
    int a,b;
    printf("\nEnter the two nos.: ");
    scanf("%d %d",&a,&b);
    printf("Gcd of two nos : %d",gcd(a,b));
    return 0;
}