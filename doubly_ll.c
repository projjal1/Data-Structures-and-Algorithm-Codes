//doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct list 
{
    int data;
    struct list *next;
    struct list *prev;
}nd;

void ins_beg(nd **ptr)
{
    nd *cur=(nd*)malloc(sizeof(nd));
    printf("\nEnter the data : ");
    scanf("%d",&cur->data);

    if((*ptr)==NULL)
    {
        (*ptr)=cur;
        cur->prev=(*ptr);
        cur->next=NULL;
    }

    else 
    {
        cur->next=(*ptr);
        (*ptr)->prev=cur;

        (*ptr)=cur;
        cur->prev=(*ptr);
    }
}

void ins_end(nd **ptr)
{
    nd *cur=(nd*)malloc(sizeof(nd));
    printf("\nEnter the data : ");
    scanf("%d",&cur->data);

    if((*ptr)==NULL)
    {
        (*ptr)=cur;
        cur->prev=(*ptr);
        cur->next=NULL;
    }

    else 
    {
        nd *trav=(*ptr);
        while((trav->next)!=NULL)
        {
            trav=trav->next;
        }
        cur->next=NULL;
        trav->next=cur;
        cur->prev=trav;
    }
}

void traversal_from_front(nd *ptr)
{
    printf("\nDisplaying list: -  ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void reversal(nd **ptr)
{
    nd *cur=(*ptr);
    nd *tmp=NULL;
    int s=0;
    while(cur!=NULL)
    {   
        if(s==0)
        {
            tmp=NULL;   //for first node make its next NULL
        }
        else
        {
            tmp=cur->prev;  //continue reversing directions
        }
        cur->prev=cur->next;
        cur->next=tmp;
        cur=cur->prev;
        s++;
    }
    if(tmp!=NULL)
    {
        (*ptr)=tmp->prev;   
    }
}

int main(void)
{
    nd *ptr;
    ptr=NULL;
    int c=3;
    while(c>0)
    {
        ins_beg(&ptr);
        traversal_from_front(ptr);
        c--;
    }    
    reversal(&ptr);
    traversal_from_front(ptr);
}