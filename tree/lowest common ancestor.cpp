#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz 100000

ll logs[sz+5];
vector <ll> graph[sz];
lca[sz+2][27];
ll level[sz+5];

void pre()
{
    logs[1] = 0;

    for(ll i=2;i<=sz;i++)
    {
        logs[i] = logs[i/2]+1;
    }
}

void dfs(ll node,ll par,ll lvl)
{
    lca[node][0] = par;
    level[node] = lvl;

    for(ll i=0;i<graph[node].size();i++)
    {
        ll next = graph[node][i];

        if(next!=par)
        {
            dfs(next,node,level[node]+1);
        }
    }
}

void init(ll nodes)
{
    ll k = logs[nodes];

    for(ll j=1;j<=k;j++)
    {
        for(ll i=0;i<=nodes;i++)
        {
            if(lca[i][j-1]!=-1)
            {
                ll par = lca[i][j-1];
                lca[i][j] = lca[par][j-1];
            }
        }
    }
}

ll getLCA(ll a,ll b,ll nodes)
{
    if(level[a]>level[b])
        swap(a,b);

    ll dist = level[b]-level[a];

    while(dist>0)
    {
        ll p = logs[dist];
        b = lca[b][p];
        dist-=(1<<p);
    }

    if(a==b)
        return a;

    ll k = logs[nodes];

    for(ll i=k;i>=0;i--)
    {
        if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }

    return lca[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();
    memset(lca,-1,sizeof(lca));

    ll nodes,i;
    cin>>nodes;

    for(i=0;i<nodes-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    init(nodes);
    dfs(1,-1,0);

    ll n1,n2;
    cin>>n1,n2;

    cout<<getLCA(n1,n2,nodes)<<endl;

    return 0;
}
