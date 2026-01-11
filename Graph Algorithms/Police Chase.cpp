#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
struct canh
{
    ll u,v,f,c;
};
canh a[20002];
int n,m,s,t,nt,d[2002],cur[2002];
bool kt[2002];
ll mx;
vector<int> v[2002];
void bfs()
{
    queue<int> q;
    fill(d,d+n+1,1e9);
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j:v[u])
        {
            auto cc=a[j];
            if(d[cc.v]!=1e9||cc.f==cc.c) continue;
            d[cc.v]=d[cc.u]+1;
            q.push(cc.v);
        }
    }
}
ll dfs(int u,ll flow)
{
    if(flow==0) return 0;
    if(u==t) return flow;
    for(;cur[u]<v[u].size();cur[u]++)
    {
        int vv=v[u][cur[u]];
        auto &cc=a[vv];
        if(d[cc.v]!=d[cc.u]+1||cc.f==cc.c) continue;
        int delta=dfs(cc.v,min(flow,cc.c-cc.f));
        if(delta==0) continue;
        cc.f+=delta;
        a[vv^1].f-=delta;
        return delta;
    }
    return 0;
}
void dfs2(int i=1)
{
    kt[i]=true;
    for(int j:v[i]){
        auto &cc=a[j];
        if(kt[cc.v]==false&&cc.c-cc.f>0)
            dfs2(cc.v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    s=1;t=n;
    for(int i=1,x,y,z;i<=m;i++)
    {
        cin>>x>>y;
        z=1;
        a[nt]={x,y,0,z};
        v[x].push_back(nt++);
        a[nt]={y,x,0,z};
        v[y].push_back(nt++);
    }
    while(true)
    {
        bfs();
        if(d[t]==1e9) break;
        for(int i=0;i<=n;i++) cur[i]=0;
        while(int delta=dfs(s,1e9))
            mx+=delta;
    }
    dfs2();
    cout<<mx<<'\n';
    for(int i=1;i<=n;i++)
        if(kt[i])
        for(int j:v[i])
    {
        auto &cc=a[j];
        if(!kt[cc.v]) cout<<i<<' '<<cc.v<<'\n';
    }
    return 0;
}
