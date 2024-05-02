#include<iostream>
using namespace std;
int a[10][10],n,indeg[10];
void find_indegree()
{
	int i,j,sum;
	for(j=0;j<n;j++)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			sum=sum+a[i][j];
		}
		indeg[j]=sum;
	}
}
void topo_sort()
{
	int i,u,v,t[10],s[10],top=-1,k=0;
	find_indegree();
	for(i=0;i<n;i++)
	{
		if(indeg[i]==0)
		{
			s[++top]=i;
		}
	}
	while(top!=-1)
	{
		u=s[top--];
		t[k++]=u;
		for(v=0;v<n;v++)
		{
			if(a[u][v]==1)
			{
				indeg[v]--;
				if(indeg[v]==0)
				{
					s[++top]=v;
				}
			}
		}
	}
	cout<<"\n"<<"Toplogical sorting is==";
	for(i=0;i<n;i++)
	{
		cout<<t[i];
	}
}
int main()
{
int i,j;
	cout<<"enter the number of vertices:=";
	cin>>n;
	cout<<"enter the adjacency matrix:==";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	topo_sort();
}