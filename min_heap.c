//Min Heap using array 
//Root always less than children

#include <stdio.h>
#define max 100

void heapify(int ar[],int no,int root,int pos)
{
    int get_pos=pos;
    if(get_pos==root)
    {
        ar[pos-1]=no;
    }
    else 
    {
        while(get_pos>root)
        {
            int index=get_pos/2;
            if(ar[index-1]>no)
            {
                ar[get_pos-1]=ar[index-1];
                get_pos=index;
            }
            else 
                break;
        }
        ar[get_pos-1]=no;
    }
}

void display(int ar[],int len)
{
    int i=0;
    for (;i<len;i++)
    {
        printf("%d ",ar[i]);
    }
}

int main()
{
    int ar[max];
    //Taking root element to be 1
    //Left child at 2*i
    //Right child at 2*i+1

    int no;
    int root=1; //Set root index to 1
    int pos=1; //Keeps track of entered element index

    while (1)
    {
        printf("\nEnter the no.:- ");
        scanf("%d",&no);
        if(no==-99999)
            break;
        else 
            heapify(ar,no,root,pos);
        display(ar,pos);
        pos+=1;
    }
}