#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define sz 1000
vector <int> graph[sz];
int indeg[sz];

void kahn(int nodes)
{
    queue <int> q;

    for(int i=1;i<=nodes;i++)
    {
        if(indeg[i]==0)     /// in degree 0 means this node has no dependency
            q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(int i=0;i<graph[node].size();i++)
        {
            int next = graph[node][i];
            indeg[next]--;
            if(indeg[next]==0)
                q.push(next);
        }
    }
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    cout<<"Topological Sorting : ";
    kahn(nodes);

    return 0;
}
