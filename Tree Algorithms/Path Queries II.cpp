#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,q,tim,mx,truy,s,x,a[200002],sz[200002],par[200002],dep[200002];
int baycak[200002],dau[200002],st[800002],vt[200002];
vector<int> v[200002];
void dfs(int i,int p)
{
    sz[i]=1;
    dep[i]=dep[p]+1;
    par[i]=p;
    int cakk=0;
    for(int j:v[i])
    {
        if(j==p) continue;
        dfs(j,i);
        sz[i]+=sz[j];
        if(sz[j]>cakk)
        {
            cakk=sz[j];
            baycak[i]=j;
        }
    }
}
void hld(int i,int p)
{
    vt[i]=++tim;
    dau[i]=p;
    if(baycak[i]!=0) hld(baycak[i],p);
    for(int j:v[i])
        if(j!=par[i]&&j!=baycak[i]) hld(j,j);
}
void update(int i,int l,int r,int vt,int gt)
{
    if(l==r)
    {
        st[i]=gt;
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    st[i]=max(st[i<<1],st[i<<1|1]);
}
int get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return -2e9;
    if(l>=a&&r<=b) return st[i];
    int mid=l+r>>1;
    return max(get(i<<1,l,mid,a,b),get(i<<1|1,mid+1,r,a,b));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("kingdom.inp","r")){
        freopen("kingdom.inp","r",stdin);
        freopen("kingdom.out","w",stdout);
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    hld(1,1);
    for(int i=1;i<=n;i++)
        update(1,1,n,vt[i],a[i]);
    while(q--)
    {
        cin>>truy>>s>>x;
        if(truy==1) update(1,1,n,vt[s],x);
        else
        {
            int mx=-1;
            while(dau[s]!=dau[x])
            {
                if(dep[dau[s]]>dep[dau[x]])
                {
                    mx=max(mx,get(1,1,n,vt[dau[s]],vt[s]));
                    s=par[dau[s]];
                }
                else
                {
                     mx=max(mx,get(1,1,n,vt[dau[x]],vt[x]));
                    x=par[dau[x]];
                }
            }
            if(dep[s]>dep[x]) swap(s,x);
            mx=max(mx,get(1,1,n,vt[s],vt[x]));
            cout<<mx<<' ';
        }
    }
    return 0;
}
