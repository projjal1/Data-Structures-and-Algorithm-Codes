//Program to create a stack

#include <stdlib.h>
#include <stdio.h>
#define max 10  //Defining max elements as 10

int stack[max];
int top=-1; //Initial index of LIFO stack

void push()
{
    if(top<max)
    {
        printf("\nEnter the element to push into stack:- ");
        scanf("%d",&stack[++top]);
    }
    else 
    {
        printf("\nStack is full");
    }
}

int pop()
{
    if(top==-1)
    {
        printf("\nUnderflow condition");
    }
    else
    {
        return stack[top--];
    }  
}

void disp()
{
    int i=top;
    for(;i>=0;i--)
        printf("%d ",stack[i]);
}

int main(void)
{
    int ch;
    do
    {
        printf("\nCurrent stack :-   ");
        disp();
        printf("\n1 to enter to stack\n2 to pop from stack");
        scanf("%d",&ch);
        if(ch==1)
            push();
        else 
            printf("\nPopped element %d",pop());
    } while (ch!=-9999);
    
}
