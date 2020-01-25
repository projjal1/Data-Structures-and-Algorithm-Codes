#include <stdio.h>

struct edge 
{
    int u,v,w;
};

struct elist 
{
    struct edge de[50];
    int n;
};

struct elist el,te;

int gp[9][9]={{0,4,0,0,0,0,0,8,0},
            {4,0,0,0,0,0,0,11,0},
            {0,8,0,7,0,4,0,0,2},
            {0,0,7,0,9,14,0,0,0},
            {0,0,0,9,0,10,0,0,0},   
            {0,0,4,14,10,0,2,0,0},
            {0,0,0,0,0,2,0,7,6},
            {8,11,0,0,0,0,7,0,7},
            {0,0,2,0,0,0,6,7,0}};

int n=9;

void sort()
{
    struct edge tmp;
    for(int i=0;i<el.n;i++)
    {
        for(int j=0;j<el.n-1;j++)
        {
            if(el.de[j].w>el.de[j+1].w)
            {
                tmp=el.de[j];
                el.de[j]=el.de[j+1];
                el.de[j+1]=tmp;
            }
        }
    }
}

int findsptree(int b[],int e)
{
    return b[e];
}

void add(int b[],int cn1,int cn2)
{
    int i=0;
    for(;i<n;i++)
    {
        if(b[i]==cn2)
            b[i]=cn1;
    }
}

void kruskal()
{
    int be[50];

    el.n=0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(gp[i][j]!=0)
            {
                el.de[el.n].u=i;
                el.de[el.n].v=j;
                el.de[el.n].w=gp[i][j];
                el.n=el.n+1;
            }            
        }
    }

    sort();

    for(int i=0;i<n;i++)
    {
        be[i]=i;
    }

    te.n=0;

    for(int i=0;i<el.n;i++)
    {
        int cn1=findsptree(be,el.de[i].u);
        int cn2=findsptree(be,el.de[i].v);

        if(cn1!=cn2)
        {
            te.de[te.n]=el.de[i];
            te.n+=1;
            add(be,cn1,cn2);
        }
    }

}

void display()
{
    int i=0;
    int cost=0;
    
    for(;i<te.n;i++)
    {
        printf("\n u =%d  v =%d  w=%d",te.de[i].u,te.de[i].v,te.de[i].w);
        cost+=te.de[i].w;
    }
    printf("\nThe cost is %d",cost);
}


int main(void)
{
    kruskal();
    display();
    return 0;
}