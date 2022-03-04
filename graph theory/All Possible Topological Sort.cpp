#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 1005

vector <ll> graph[sz];
bool vis[sz];
vector <ll> result;
ll indeg[sz];
ll n,m;

void allPossibleTopoSort()
{
    if(result.size()==n)
    {
        for(ll i=0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;
        return;
    }

    for(ll i=0;i<n;i++)
    {
        if(indeg[i]==0 && !vis[i])
        {
            result.push_back(i);
            vis[i] = true;

            for(ll j=0;j<graph[i].size();j++)
            {
                indeg[graph[i][j]]-=1;
            }

            allPossibleTopoSort();

            vis[i] = false;
            result.pop_back();

            for(ll j=0;j<graph[i].size();j++)
            {
                indeg[graph[i][j]]+=1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i;
    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    allPossibleTopoSort();
}
