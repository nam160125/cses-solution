#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,up[19][200002],dep[200002],a,b,d[200002];
bool kt[200002];
vector<int> v[200002];
void dfs(int i,int p)
{
    dep[i]=dep[p]+1;
    up[0][i]=p;
    for(int k=1;k<=18;k++)
        up[k][i]=up[k-1][up[k-1][i]];
    for(int j:v[i])
        if(j!=p) dfs(j,i);
}
void bfs()
{
    queue<int> q;
    kt[1]=true;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j:v[u])
            if(kt[j]==false)
            {
                kt[j]=true;
                d[j]=d[u]+1;
                q.push(j);
            }
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=18;k>=0;k--)
        if(dep[up[k][u]]>=dep[v]) u=up[k][u];
    if(u==v) return u;
    for(int k=18;k>=0;k--)
        if(up[k][u]!=up[k][v])
    {
        u=up[k][u];
        v=up[k][v];
    }
    return up[0][u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    bfs();
    while(q--)
    {
        cin>>a>>b;
        int xx=lca(a,b);
        cout<<d[a]+d[b]-2*d[xx]<<'\n';
    }
    return 0;
}
