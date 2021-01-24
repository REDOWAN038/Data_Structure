#include<bits/stdc++.h>
using namespace std;
#define sz 1000
vector <int> adj[sz],radj[sz],order,scc;
bool visited[sz];

void dfs1(int node)
{
	visited[node] = true;

	for(int i=0;i<adj[node].size();i++)
	{
		int next = adj[node][i];

		if(!visited[next])
			dfs1(next);
	}

	order.push_back(node);
}

void dfs2(int node)
{
	visited[node] = true;

	for(int i=0;i<radj[node].size();i++)
	{
		int next = radj[node][i];

		if(!visited[next])
			dfs2(next);
	}

	scc.push_back(node);
}
int main()
{
	int n,m,i;
	cin>>n>>m;

	for(i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		radj[y].push_back(x);
	}

	for(i=0;i<n;i++)
	{
		if(!visited[i])
			dfs1(i);
	}

	for(i=0;i<n;i++)
		visited[i] = false;

	for(i=n-1;i>=0;i--)
	{
		if(!visited[order[i]])
		{
			dfs2(order[i]);

			cout<<"scc starting from node "<<order[i]<<" and components are : ";

			for(int j=0;j<scc.size();j++)
				cout<<scc[j]<<" \n"[j==scc.size()-1];

			scc.clear();
		}
	}

	return 0;
}