#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int up[19][200002],d[200002],par[200002];
int n,k,dep[200002];
vector<int> v[200002];
void dfs(int i,int p)
{
    par[i]=p;
    dep[i]=dep[p]+1;
    up[0][i]=p;
    for(int k=1;k<19;k++)
        up[k][i]=up[k-1][up[k-1][i]];
    for(int j:v[i])
    {
        if(j==p) continue;
        dfs(j,i);
    }
}
void dfs2(int i,int p)
{
    for(int j:v[i])
    {
        if(j==p) continue;
        dfs2(j,i);
        d[i]+=d[j];
    }
}
int lca(int u,int v)
{
    int a=u,b=v;
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=18;k>=0;k--)
        if(dep[up[k][u]]>=dep[v])
            u=up[k][u];
    if(u==v)
        return u;
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
    cin>>n>>k;
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1,x,y;i<=k;i++)
    {
        cin>>x>>y;
        d[x]++;
        d[y]++;
        int xx=lca(x,y);
        d[xx]--;
        if(xx!=1) d[par[xx]]--;
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';
    return 0;
}
