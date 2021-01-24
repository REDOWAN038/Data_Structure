#include<bits/stdc++.h>
using namespace std;
#define sz 10000
vector <int> graph[sz];
int weight[sz][sz];
bool visited[sz];
bool ok;
int dist[sz];
int parent[sz];
int nodes,edges;

bool dijstra(int source,int dest)
{
	int i;
	for(i=0;i<nodes;i++)
		dist[i] = INT_MAX;

	priority_queue < pair <int,int>, vector<pair <int,int> >,greater<pair <int,int> > > pq;
	dist[source] = 0;
	pq.push({dist[source],source});
	parent[source] = -1;

	while(!pq.empty())
	{
		pair <int,int> node = pq.top();
		pq.pop();
		visited[node.second] = true;
		for(i=0;i<graph[node.second].size();i++)
		{
			int next = graph[node.second][i];
			if(visited[next]==false)
			{
				if((node.first+weight[node.second][next])<dist[next])
				{
					dist[next] = node.first+weight[node.second][next];
					parent[next] = node.second;
					pq.push({dist[next],next});
					if(next==dest)
						ok = true;
				}
			}
		}
	}

	return ok;
}

void print_path(int a,int b)
{
	if(a==b)
		return;
	print_path(parent[a],b);
	cout<<a<<" ";
}
int main()
{
	int i;
	cin>>nodes>>edges;

	for(i=0;i<edges;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back(y);
		graph[y].push_back(x);
		weight[x][y] = w;
		weight[y][x] = w;
	}

	int source,dest;
	cin>>source>>dest;
	
	if(dijstra(source,dest))
		{
			cout<<source<<" ";
			print_path(dest,source);
		}
	else 
		cout<<"No such path"<<endl;
	
	/*for(i=1;i<nodes;i++)
		cout<<dist[i]<<endl;*/

	return 0;
}