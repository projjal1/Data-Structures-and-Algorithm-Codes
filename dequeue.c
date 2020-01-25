//Single ended queue

#include <stdio.h>
#include <stdlib.h>
#define max 5 //Max no. of elements in queue

int ar[max];
int rear,front;

void init()
{
    rear=front=-1;  //Initializing index of both
}

void insert()
{
    if(front==max-1 )
    {
        printf("Queue is full");
        return ;
    }
    if(rear==-1)
    {
        front++;
        rear++;
    }
    else 
    {
        front++;
    }
    printf("\nEnter the no . ");
    scanf("%d",&ar[front]);
}

int delete()
{
    int elem;
    if(rear==-1)
    {
        printf("\nQueue is empty");
    }
    else 
    {
        elem=ar[rear];
        rear++;
    }
    if(rear>front)
    {
        init();//Queue is completely empty now and reseted thus
    }
    return elem;
}

void disp()
{
    int i=0;
    if(rear==-1)
    {
        printf("\nQueue underflow");
        return ;
    }
    for(i=rear;i<=front;i++)
    {
        printf("%d ",ar[i]);
    }
}

int main(void)
{
    int ch;
    init();
    do
    {
        printf("\nQueue status :- ");
        disp();
        printf("\n1 for insert \n2 for delete \n"); 
        scanf("%d",&ch);
        if(ch==1)
            insert();
        else if(ch==2)
            printf("\nPopped element is %d",delete());   
    }
    while (ch!=-9999);    
}