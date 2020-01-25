#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
}nd;

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
        nd *prev;  //Stores previous pointer
        while((cur)!=NULL)
        {
            prev=cur;
            if(sc<(cur->data))
            {
                cur=cur->left;
            }
            else if (sc>(cur->data))
            {
                cur=cur->right;
            }
            else if(sc==(cur->data))
            {
                printf("\nUnable to insert as element already present");
            }
        }
        if(prev->data>sc)
        {
            prev->left=ptr;
        }
        else 
        {
            prev->right=ptr;
        }
    }
}

void delete(nd **root)
{
    int n;
    printf("\nElement to delete := ");
    scanf("%d",&n);

    if((*root)->data==n)
    {
        nd *cur=(*root);
        nd *right_tree=cur->right;
        nd *left_tree=cur->left;
        free((*root));      //deleting root
        (*root)=cur->left;   //Setting head to current variable
        cur=cur->left;    //Setting current pointer to head variable
        while(cur->right!=NULL)   //Browsing right subtree for last rightmost elem
        {
            cur=cur->right;
        }
        cur->right=right_tree;   //Then adding right part of previous head to it
    }
    else 
    {
        nd *prev;
        nd *cur=(*root);
        while((cur->data)!=n)
        {
            prev=cur;
            if(n<cur->data)
            {
                cur=cur->left;
            }
            else if(n>cur->data)
            {
                cur=cur->right;
            }
            else 
            {
                printf("\nElement not present");
                return;
            }
        }

        if(n<(prev->data))
        {
            if(cur->right==NULL && cur->left==NULL)
            {
                prev->left=NULL;
                free(cur); 
                return;
            }
            if(cur->right==NULL)
            {
                prev->left=cur->left;
                free(cur);
                return;
            }
            if(cur->left==NULL)
            {
                prev->left=cur->right;
                free(cur);
                return;
            }
            else
            {
                prev->left=cur->left;
                nd *right_tree=cur->right;
                nd *left_tree=cur->left;
                free(cur);
                while((left_tree->right)!=NULL)
                {
                    left_tree=left_tree->right;
                }
                left_tree->right=right_tree;
            }
        }     

        else
        {
            if(cur->right==NULL && cur->left==NULL)
            {
                prev->right=NULL;
                free(cur); 
                return;
            }
            if(cur->right==NULL)
            {
                prev->right=cur->left;
                free(cur);
                return;
            }
            if(cur->left==NULL)
            {
                prev->right=cur->right;
                free(cur);
                return;
            }
            else
            {
                prev->right=cur->left;
                nd *right_tree=cur->right;
                nd *left_tree=cur->left;
                free(cur);
                while((left_tree->right)!=NULL)
                {
                    left_tree=left_tree->right;
                }
                left_tree->right=right_tree;
            }
        }         
    }
}

void inorder_trav(nd *root)
{
    if(root!=NULL)
    {
        inorder_trav(root->left);
        printf("%d ",root->data);
        inorder_trav(root->right);
    }
}


void postorder_trav(nd *root)
{
    if(root!=NULL)
    {
        postorder_trav(root->left);        
        postorder_trav(root->right);
        printf("%d ",root->data);
    }
}

void smallest_element(nd *root)
{
    while((root->left)!=NULL)    //smallest element is always present in the left subarray of the bst
    {
        root=root->left;
    }
    printf("\nSmallest element in the bst is : -  %d",root->data);
}

void largest_element(nd *root)
{
    while((root->right)!=NULL)    //largest element is always present in the right subarray of the bst
    {
        root=root->right;
    }
    printf("\nLargest element in the bst is : -  %d",root->data);
}

void preorder_trav(nd *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder_trav(root->left);        
        preorder_trav(root->right);        
    }
}

int main(void)
{
    int c=4;
    nd *root=NULL;
    while(c>0)
    {
        insert(&root);
        c--;
    }
    printf("\nInorder traversal :- ");
    inorder_trav(root);
    delete(&root);
    printf("\nInorder traversal :- ");
    inorder_trav(root);
}