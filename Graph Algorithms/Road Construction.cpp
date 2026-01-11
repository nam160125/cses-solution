#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,m,p[100002],tplt,mx=1;
int finds(int u)
{
    return p[u]<0?u:p[u]=finds(p[u]);
}
void soviet(int u,int v)
{
    u=finds(u),v=finds(v);
    if(u==v) return;
    if(p[u]>p[v]) swap(u,v);
    p[u]+=p[v];
    tplt--;
    mx=max(mx,abs(p[u]));
    p[v]=u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    tplt=n;
    fill(p+1,p+n+1,-1);
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        soviet(x,y);
        cout<<tplt<<' '<<mx<<'\n';
    }
    return 0;
}
