#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll,ll>
using namespace std;
int n,q,l,r,cid,up[19][200002],d[200002],comp[200002],sz[200002];
int p[200002];
bool kt[200002];
vector<int> v[200002],goc;
int nhay(int cur,int step)
{
    for(int k=18;k>=0;k--)
        if(step&(1<<k))
        cur=up[k][cur];
    return cur;
}
int finds(int u)
{
    return p[u]<0?u:p[u]=finds(p[u]);
}
bool soviet(int u,int v)
{
    u=finds(u);v=finds(v);
    if(u==v) return false;
    if(p[u]>p[v]) swap(u,v);
    p[u]+=p[v];
    p[v]=u;
    return true;
}
void dfs(int i,int tp)
{
    kt[i]=true;
    comp[i]=tp;
    for(int j:v[i])
    {
        if(kt[j]==false)
        {
            d[j]=d[i]+1;
            dfs(j,tp);
        }
        else sz[i]=d[i]+1;
        sz[i]=max(sz[i],sz[j]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    fill(p,p+n+1,-1);
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
        up[0][i]=x;
        if(!soviet(x,i)) goc.push_back(x);
    }
    for(int k=1;k<19;k++)
        for(int i=1;i<=n;i++)
        up[k][i]=up[k-1][up[k-1][i]];
    for(int i:goc)
        dfs(i,++cid);
    while(q--)
    {
        cin>>l>>r;
        if(l==r) cout<<0<<'\n';
        else
        if(comp[l]!=comp[r]) cout<<-1<<'\n';
        else if(sz[l])
        {
            if(!sz[r]) cout<<-1<<'\n';
            else cout<<(d[l]-d[r]+sz[l])%sz[l]<<'\n';
        }
        else if(!sz[r])
        {
            if(d[l]<=d[r]) cout<<-1<<'\n';
            else cout<<(nhay(l,d[l]-d[r])==r?d[l]-d[r]:-1)<<'\n';
        }
        else
        {
            int dem=0;
            for(int k=18;k>=0;k--)
                if(!sz[up[k][l]]){
                l=up[k][l];
                dem+=(1<<k);
            }
            l=up[0][l];
            dem++;
            if(l==r) cout<<dem<<'\n';
            else
                cout<<dem+(d[l]-d[r]+sz[l])%sz[l]<<'\n';
        }
    }
    return 0;
}
