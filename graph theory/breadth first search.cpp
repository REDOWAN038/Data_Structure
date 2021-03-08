/// BFS  ----->  Breadth First Search
/// Time Complexity -----> O(V+E) [ V  = vertices and E = edges]

#include<bits/stdc++.h>
using namespace std;

#define sz 100
vector <int> graph[sz];
bool visited[sz];
int dist[sz];

void bfs(int source)
{
    visited[source] = 1;
    dist[source] = 0;
    queue <int> q;
    q.push(source);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++)
        {
            int next = graph[node][i];
            if(visited[next]==0)
            {
                visited[next] = 1;
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int nodes,edges,i;
    cin>>nodes>>edges;
    for(i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);    /// undirected graph
        graph[v].push_back(u);
    }

    int source;     /// starting node
    cin>>source;
    bfs(source);
    cout<<"From node "<<source<<" : "<<endl;
    for(i=1;i<=nodes;i++)
        cout<<"Distance of node"<<i<<" is "<<dist[i]<<endl;

    return 0;

}
