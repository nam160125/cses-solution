#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,up[19][200002],dep[200002],a,b;
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
    for(int i=2,x;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    dfs(1,0);
    while(q--)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
    return 0;
}
