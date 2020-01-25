#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}nd;

void disp(nd *root)
{
    printf("\nDisplaying linked list  :-   ");
    if(root==NULL)
        printf("List is empty");
    else 
    {
        nd *head=root;
        do
        {
            printf("%d ",root->data);
            root=root->next;
        } 
        while ((root)!=head);
    }
        
}

void ins_beg(nd **root)
{
    nd *ptr=(nd*)malloc(sizeof(nd*));
    printf("\nEnter the data:- ");
    int no;
    scanf("%d",&no);
    ptr->data=no;
    
    //Root is null
    if((*root)==NULL)
    {
        (*root)=ptr;
        ptr->next=(*root);
    }

    //List is not empty
    else
    {
        nd *prev_head=(*root);  //Stores previous root pointer
        ptr->next=(*root);
        (*root)=ptr;

        nd *cur=(*root);
        do
        {
            cur=cur->next;
        } while ((cur->next)!=prev_head);
        cur->next=(*root);
    }
}

void ins_end(nd **root)
{
    nd *ptr=(nd*)malloc(sizeof(nd*));
    printf("\nEnter the data:- ");
    int no;
    scanf("%d",&no);
    ptr->data=no;
    
    //Root is null
    if((*root)==NULL)
    {
        (*root)=ptr;
        ptr->next=(*root);
    }

    //List is not empty
    else
    {
        nd *prev_head=(*root);  //Stores previous root pointer
        
        nd *cur=(*root);
        do
        {
            cur=cur->next;
        } while ((cur->next)!=prev_head);
        cur->next=ptr;
        ptr->next=prev_head;        
    }
}

int main(void)
{
    int c=6;
    nd *root=NULL;
    while(c>0)
    {
        if(c%2==0)
            ins_beg(&root);
        else
            ins_end(&root);
        disp(root);
        c--;
    }
}