#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int par[sz];

struct edges {

	int a;
	int b;
	int w;
}graph[sz];

bool cmp(edges a,edges b)
{
	if(a.w<b.w)
		return true;
	return false;
}

int find_parent(int a)
{
	if(par[a]==0)
		return a;
	else
		return find_parent(par[a]);
}

void merge(int a,int b)
{
	par[a] = b;
}

int main()
{
	int n,m,i,sum=0;
	cin>>n>>m;

	for(i=0;i<m;i++)
		cin>>graph[i].a>>graph[i].b>>graph[i].w;

	sort(graph,graph+m,cmp);

	for(i=0;i<m;i++)
	{
		int x,y;
		x = find_parent(graph[i].a);
		y = find_parent(graph[i].b);

		if(x!=y)
		{
			sum+=graph[i].w;
			merge(x,y);
		}
	}

	cout<<sum<<endl;
}