#include<bits/stdc++.h>
using namespace std;

vector <int> graph[100];
bool visited[100];
vector <int> result;

void dfs(int source)
{
    visited[source] = 1;
    for(int i=0;i<graph[source].size();i++)
    {
        int next = graph[source][i];
        if(visited[next]==0)
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
        graph[u].push_back(v);
    }

    for(i=0;i<nodes;i++)
    {
        if(visited[i]==0)
            dfs(i);
    }

    reverse(result.begin(),result.end());
    cout<<"Topological sort : ";
    for(i=0;i<result.size()-1;i++)
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}
