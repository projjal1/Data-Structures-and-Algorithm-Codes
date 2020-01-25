#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}nd;

int count(nd *head)
{
    int s=0;
    nd *trav;
    trav=head;
    while(trav!=NULL)
    {
        s+=1;
        trav=trav->next;
    }
    return s;
}

void ins_beg(nd **head)
{
    nd *ptr;
    ptr=(nd*)malloc(sizeof(nd));
    printf("\nEnter the data = ");
    scanf("%d",&(ptr->data));

    if((*head)==NULL) 
    {
        ptr->next=NULL;
        (*head)=ptr;
    }
    else if((*head)!=NULL)
    {
        nd *cur=(*head);
        ptr->next=cur;
        (*head)=ptr;
    }
}

void ins_end(nd **head)
{
    nd *ptr;
    ptr=(nd*)malloc(sizeof(nd));
    printf("\nEnter the data = ");
    scanf("%d",&(ptr->data));
    ptr->next=NULL;

    if((*head)==NULL) 
    {
        (*head)=ptr;
        
    }
    else if((*head)!=NULL)
    {
        nd *cur=(*head);
        while((cur->next)!=NULL)
        {
            cur=cur->next;
        }
        cur->next=ptr;
    }
}

void ins_mid_after(nd **head)
{
    int len=count((*head));

    int pos;
    do
    {
        printf("\nEnter the no. of nodes after you want to insert");
        scanf("%d",&pos);
    }while(pos>len || pos<1);
    
    if(pos==len)
    {
        ins_end(head);
        return;
    }
    
    nd *ptr;
    ptr=(nd*)malloc(sizeof(nd));
    printf("\nEnter the data = ");
    scanf("%d",&(ptr->data));

    nd *prev=(*head);
    nd *nxt=(*head)->next;

    int i=2;
    for(;i<=pos;i++)
    {
        prev=prev->next;
        nxt=nxt->next;
    }
    ptr->next=nxt;
    prev->next=ptr;   

}

void ins_mid_before(nd **head)
{
    int len=count((*head));

    int pos;
    do
    {
        printf("\nEnter the no. of nodes before you want to insert");
        scanf("%d",&pos);
    }while(pos>len || pos<1);
    
    if(pos==1)
    {
        ins_beg(head);
        return;
    }
    
    nd *ptr;
    ptr=(nd*)malloc(sizeof(nd));
    printf("\nEnter the data = ");
    scanf("%d",&(ptr->data));

    nd *prev=(*head);
    nd *nxt=(*head)->next;

    int i=2;
    for(;i<pos;i++)
    {
        prev=prev->next;
        nxt=nxt->next;
    }
    ptr->next=nxt;
    prev->next=ptr;   

}

void del_beg(nd **head)
{
    if((*head!=NULL))
    {
        (*head)=(*head)->next;
        return;
    }
    else 
    {
        printf("\nNot possible as list is empty");
    }
}

void del_end(nd **head)
{
    if((*head!=NULL))
    {
        nd *cur=(*head);
        while(((cur->next)->next)!=NULL)
        {
            cur=cur->next;
        }
        cur->next=NULL;
    }
    else 
    {
        printf("\nNot possible as list is empty");
    }
}

void del_pos(nd **head)
{
    int len=count((*head));

    int pos;
    do
    {
        printf("\nEnter the pos of node you want to delete");
        scanf("%d",&pos);
    }while(pos>len || pos<1);
    
    if(pos==len)
    {
        del_end(head);
        return;
    }
    if(pos==1)
    {
        del_beg(head);
        return ;
    }
    

    nd *prev=(*head);
    nd *nxt=(*head)->next;

    int i=2;
    for(;i!=pos;i++)
    {
        prev=prev->next;
        nxt=nxt->next;
    }
    prev->next=(nxt->next);  

}

void traverse(nd *head)
{
    nd *trav;
    trav=head;
    while(trav!=NULL)
    {
        printf("%d ",trav->data);
        trav=trav->next;
    }
}

int main(void)
{
    nd *head=NULL;
    int c=9;
    
    while(c>0)
    {
        printf("\nInsertion at the beginning");
        ins_beg(&head);
        c--;
    }
    traverse(head);
    c=4;
    while(c>0)
    {
        if(c%2==0)
        {
            printf("\nDeleting beginning");
            del_beg(&head);
        }
        else 
        {
            printf("\nDeleting at the end");
            del_end(&head);
        }
        traverse(head);
        c--;
    }
    c=2;
    while(c>0)
    {
        printf("\nDeleting at the position");
        del_pos(&head);
        c--;
        traverse(head);
    }
}
    