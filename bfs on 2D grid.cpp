#include<bits/stdc++.h>
using namespace std;
#define sz 100
bool visited[sz][sz];
int dist[sz][sz];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int r,c;

bool isvalid(int x,int y)
{
	if(x<0 || y<0 || x>r-1 || y>c-1)
		return false;
	if(visited[x][y])
		return false;
	return true;
}

void bfs(int srcx,int srcy)
{
	visited[srcx][srcy] = true;
	dist[srcx][srcy] = 0;
	queue < pair<int,int> > q;
	q.push({srcx,srcy});

	while(!q.empty())
	{
		int nodex = q.front().first;
		int nodey = q.front().second;
		q.pop();

		for(int i=0;i<4;i++)
		{
			if(isvalid(nodex+dx[i],nodey+dy[i]))
			{
				int nextx = nodex+dx[i];
				int nexty = nodey+dy[i];
				visited[nextx][nexty] = true;
				dist[nextx][nexty] = dist[nodex][nodey] + 1;
				q.push({nextx,nexty});
			}
		}
	}
}
int main()
{
	int x,y,i,j;
	cin>>r>>c>>x>>y;
	bfs(x,y);

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<dist[i][j]<<" ";
		}

		cout<<endl;
	}

	return 0;
}