#include<bits/stdc++.h>
using namespace std;
#define sz 1000

vector <int> graph[sz];
int indeg[sz];
vector <int> level;

void toposort(int nodes)
{
    queue <int> q;

    for(int i=0; i<nodes; i++)
    {
        if(indeg[i]==0)
            level.push_back(i);
    }

    sort(level.begin(),level.end());

    for(int i=0; i<level.size(); i++)
    {
        q.push(level[i]);
    }

    level.clear();

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int i=0; i<graph[node].size(); i++)
        {
            int next = graph[node][i];

            indeg[next]--;

            if(indeg[next]==0)
                level.push_back(next);
        }

        if(q.size()==0)
        {
            sort(level.begin(),level.end());

            for(int i=0; i<level.size(); i++)
            {
                q.push(level[i]);
            }

            level.clear();
        }
    }
}

int main()
{
    int nodes,edges,i;
    cin>>nodes>>edges;

    for(i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    cout<<"Lexicographically Shortest Toposort : ";
    toposort(nodes);

}

