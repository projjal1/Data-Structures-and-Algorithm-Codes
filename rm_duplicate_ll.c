#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}node;

void input(node **ptr,int n)
{
    node *cur=(node*)malloc(sizeof(node));
    cur->data=n;
    cur->next=NULL;

    if(*ptr==NULL)
    {
        *ptr=cur;
    }

    else
    {
        node *point=*ptr;
        while(point->next!=NULL)
        {
            point=point->next;
        }
        point->next=cur;
    }    
}

void disp(node *ptr)
{
    printf("\nDisplaying list:\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int check(int no,node **ptr)
{
    node *c=*ptr;
    while(c!=NULL)
    {
        if(c->data==no)
            return 0;
        c=c->next;
    }
    return 1;
}

node** rm(node *ptr1,node **ptr2)
{
    while(ptr1!=NULL)
    {
        int flag=0;
        if((*ptr2)==NULL)
        {
            input(ptr2,ptr1->data);
        }
        else 
        {   if(check(ptr1->data,ptr2)!=0)
            {
                input(ptr2,ptr1->data);        
            }
        }
        ptr1=ptr1->next;
    }
    return ptr2;
}

int main(void)
{   
    node *ptr1;  //original list
    node *ptr2;  //list with duplicates removed

    //initialization
    ptr1=NULL;
    ptr2=NULL;

    int n;
    printf("\nEnter the no. of elements to enter:");
    scanf("%d",&n);

    int tmp;
    int i=0;
    for(;i<n;i++)
    {
        printf("\nEnter element :");
        scanf("%d",&tmp);
        input(&ptr1,tmp);
    }

    disp(ptr1);
    rm(ptr1,&ptr2);

    disp(ptr2);

    return 0;
}