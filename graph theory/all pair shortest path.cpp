/// Floyd-Warshall algo
/// Time Complexity ---> O(nodes^3)

#include<iostream>
#include<algorithm>
using namespace std;
#define inf 100000

int main()
{
	int nodes,edges;
	cout<<"Enter number of nodes ans edges : ";
	cin>>nodes>>edges;
	cout<<endl;
	int dist[nodes][nodes];

	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
            dist[i][j] = inf;  /// assign with infinity
		}
	}

	cout<<"Enter direct path ('0' based index) and their weight : "<<endl;

	for(int i=0;i<edges;i++)
	{
	    int u,v,w;
		cin>>u>>v>>w;
		dist[u][v] = w;
		dist[v][u] = w;
	}

	for(int k=0;k<nodes;k++)
	{
		for(int i=0;i<nodes;i++)
		{
			for(int j=0;j<nodes;j++)
			{
				dist[i][j] = min(dist[i][j],(dist[i][k]+dist[k][j]));
			}
		}
	}

	cout<<"All pair shortest path matrix : "<<endl;

	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			cout<<dist[i][j]<<" ";
		}

		cout<<endl;
	}

	return 0;
}
