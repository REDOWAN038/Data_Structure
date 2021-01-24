#include<bits/stdc++.h>
using namespace std;

vector <int> graph[30];
bool visited[30];

void dfs(int source)
{
    visited[source] = true;
    for(int i=0;i<graph[source].size();i++)
    {
        int next = graph[source][i];
        if(!visited[next])
          return  dfs(next);
    }
}
int main()
{
    int nodes,edges,i;
    cin>>nodes>>edges;

    for(i=0;i<edges;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(i=0;i<nodes;i++)
    {
        if(!visited[i])
            dfs(i);
    }

    for(i=0;i<nodes;i++)
    {
        if(visited[i])
            cout<<"Node "<<i<<" is visited"<<endl;
    }

    return 0;
}
