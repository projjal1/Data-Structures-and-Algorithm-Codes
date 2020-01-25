//Program to demonstrate the Eucleidian method of solving for GCD

#include <stdio.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    printf("\nEnter the two nos.\n");
    scanf("%d %d",&a,&b);
    int max,min;
    max=(a>b)?a:b;
    min=(a<b)?a:b;
    printf("The GCD of two nos. is = %d",gcd(max,min));
}