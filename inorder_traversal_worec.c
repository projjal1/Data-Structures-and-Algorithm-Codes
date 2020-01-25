//Inorder traversal without recursion

#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
}nd;

nd* var[max];

int top=-1;

int insert(nd **root)
{
    int sc;
    
    printf("\nEnter the data = ");
    scanf("%d",&sc);

    nd *ptr=(nd*)malloc(sizeof(nd));
    ptr->data=sc;
    ptr->right=NULL;
    ptr->left=NULL;

    if((*root)==NULL)
    {
        (*root)=ptr;
    }
    else
    {
        nd *cur=(*root);
        while(cur!=NULL)
        {
            if(sc<(cur->data))
            {
                if(cur->left==NULL)
                {
                    cur->left=ptr;
                    return;
                }
                cur=cur->left;
            }
            else if (sc>(cur->data))
            {
                if(cur->right==NULL)
                {
                    cur->right=ptr;
                    return;
                }
                cur=cur->right;
            }
            else if(sc==(cur->data))
            {
                printf("\nUnable to insert as element already present");
            }
        }
    }
}

void push(nd *elem)
{
    top+=1;
    var[top]=elem;
}

nd* pop()
{
    nd *ele=var[top];
    top--;
    return ele;
}

void inorder_trav(nd *root)
{
    while(root!=NULL || top!=-1)
    {
        while(root!=NULL)
        {
            push(root);
            root=root->left;
        }
        
        root=pop();
        printf("%d ",root->data);
        root=root->right;
    }
}

int main(void)
{
    int c=8;
    nd *root=NULL;
    while(c>0)
    {
        insert(&root);
        c--;
    }
    printf("\nInorder traversal :- ");
    inorder_trav(root);
    printf("\nInorder traversal :- ");
    inorder_trav(root);
}
