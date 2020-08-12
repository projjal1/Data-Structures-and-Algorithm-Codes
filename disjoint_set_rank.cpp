#include<iostream>
using namespace std;

class DisjSet
{
	int *rank,*parent,n;
	
	public:
		//Constructor to initialize DS
		DisjSet(int n)
		{
			rank=new int[n];
			parent=new int[n];
			this->n=n;
			makeSet();
		}
		
		//A single list of items 
		void makeSet()
		{
			for(int i=0;i<n;i++)
				parent[i]=i;
		}
		
		//Finds the set of given item x 
		int find(int x)
		{
			if (parent[x]!=x)
			{
				//Basically if x is not the parent of itself, then it is not representative of a set
				//So we need to find the set to which x belongs
				parent[x]=find(parent[x]);
			}
			return parent[x];
		}
		
		//Now we do the union of two sets 
		//by x & y
		void Union(int x,int y)
		{
			//Find the representative of sets 
			int xset=find(x);
			int yset=find(y);
			
			//If already in same set they will have same representative
			if (xset==yset)
				return ;
			
			//Else find the ranks 
			int rank1=rank[xset];
			int rank2=rank[yset];
			
			//Put smaller ranked item under bigger ranked 
			if (rank1<rank2)
				parent[xset]=yset;
			else if (rank1>rank2) 
				parent[yset]=xset;
			else 
			{
				parent[yset]=xset;
				rank[xset]+=1;
			}
		}
};

//Now writing the driver code
int main()
{
	DisjSet obj(5);
	obj.Union(0,2);
	obj.Union(4,2);
	obj.Union(3,1);
	
	if (obj.find(4)==obj.find(0))
		cout<<"4 and 0 exists in same set";
	else 
		cout<<"4 and 0 exists in diff set";
	
	if (obj.find(1)==obj.find(0))
		cout<<"0 and 1 exists in same set";
	else 
		cout<<"0 and 1 exists in diff set";
	
	return 0;
}
