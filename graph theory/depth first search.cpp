/// DFS ----> Depth First Search
/// Time Complexity ----> O(V+E)   [V = vertices and E = edges]

#include<bits/stdc++.h>
using namespace std;

#define sz 100
vector <int> graph[sz];
bool visited[sz];

void dfs(int source)
{
    cout<<source<<" ";
    visited[source] = true;

    for(int i=0;i<graph[source].size();i++)
    {
        int next = graph[source][i];
        if(!visited[next])
            dfs(next);
    }
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);      /// directed graph
    }

    int source;
    cin>>source;

    cout<<"DFS traversal from node "<<source<<": \n";

    dfs(source);

    for(int i=1;i<=nodes;i++)   /// for handling disconnected graph
    {
        if(!visited[i])
            dfs(i);
    }

    return 0;
}
