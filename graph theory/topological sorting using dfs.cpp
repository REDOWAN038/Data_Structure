/// Time Complexity ----> O(V+E)   [V = vertices and E = edges]

#include<bits/stdc++.h>
using namespace std;

#define sz 100
vector <int> graph[sz];
bool visited[sz];
vector <int> result;

void dfs(int source)
{
    visited[source] = true;
    for(int i=0;i<graph[source].size();i++)
    {
        int next = graph[source][i];
        if(!visited[next])
            dfs(next);
    }

    result.push_back(source);
}

int main()
{
    int nodes,edges,i;
    cin>>nodes>>edges;

    for(i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);      /// directed graph
    }

    for(i=1;i<=nodes;i++)
    {
        if(!visited[i])
            dfs(i);
    }

    reverse(result.begin(),result.end());
    cout<<"Topological sort : ";
    for(i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}
