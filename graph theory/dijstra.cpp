/// find shortest distance between two nodes
/// this algorithm will fail if a graph have negative weight cycle

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define sz 10000

vector <int> graph[sz];
int weight[sz][sz];
int dist[sz];
int parent[sz];

bool dijstra(int source,int dest)
{
    priority_queue < pair <int,int>, vector<pair <int,int> >,greater<pair <int,int> > > pq;     /// creating min heap
    dist[source] = 0;
    pq.push({dist[source],source});
    parent[source] = -1;
    bool ok = false;

    while(!pq.empty())
    {
        pair <int,int> node = pq.top();
        pq.pop();

        for(int i=0; i<graph[node.second].size(); i++)
        {
            int next = graph[node.second][i];
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

    return ok;
}

void print_path(int a,int b)
{
    if(a==b)
        return;
    print_path(parent[a],b);
    cout<<a+1<<" ";
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0; i<nodes; i++)
        dist[i] = INT_MAX;

    for(int i=0; i<edges; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        --x;
        --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        weight[x][y] = w;
        weight[y][x] = w;
    }

    int source,dest;
    cin>>source>>dest;
    --source;
    --dest;

    if(dijstra(source,dest))
    {
        cout<<"The minimum path distance from "<<source+1<<" to "<<dest+1<<" is : "<<dist[dest]<<endl;
        cout<<"The path is : ";
        cout<<source+1<<" ";
        print_path(dest,source);
        cout<<endl;
    }
    else
        cout<<"No such path"<<endl;

    return 0;
}


