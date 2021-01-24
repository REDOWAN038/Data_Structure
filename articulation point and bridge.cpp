#include<bits/stdc++.h>
using namespace std;
#define sz 1000
vector <int> adj[sz],arti_point;
int d[sz],low[sz],timee;
bool visited[sz];

void find_articulation_point(int u,int par)
{
	visited[u] = true;
	d[u] = low[u] = ++timee;
	int child=0,i,v;

	for(i=0;i<adj[u].size();i++)
	{
		v = adj[u][i];

		if(v==par)
			continue;

		if(visited[v])
			low[u] = min(low[u],d[v]);
		else
		{
			find_articulation_point(v,u);
			low[u] = min(low[u],low[v]);

			if(d[u]<=low[v] && par!=-1)
				arti_point.push_back(u);
			else
				child++;
		}

		if(child>1 && par==-1)
			arti_point.push_back(u);
	}
}
int main()
{
	int i,n,m,x,y;
	cin>>n>>m;

	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	find_articulation_point(0,-1);

	sort(arti_point.begin(),arti_point.end());


	for(i=0;i<arti_point.size();i++)
		cout<<arti_point[i]<<endl;

	return 0;
}