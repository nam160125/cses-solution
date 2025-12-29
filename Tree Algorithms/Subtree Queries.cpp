#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,q,st[200002],en[200002],tour[200002],a[200002],m,truy,s,x;
vector<int> v[200002];
ll seg[4000002];
void update(int i,int l,int r,int vt,int gt)
{
    if(l==r)
    {
        seg[i]=gt;
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    seg[i]=seg[i<<1]+seg[i<<1|1];
}
ll get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return 0;
    if(l>=a&&r<=b) return seg[i];
    int mid=l+r>>1;
    return get(i<<1,l,mid,a,b)+get(i<<1|1,mid+1,r,a,b);
}
void dfs(int i,int p)
{
    st[i]=++m;
    tour[m]=i;
    for(int j:v[i])
        if(j!=p) dfs(j,i);
    en[i]=m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("PATH.inp","r"))
    {
        freopen("PATH.inp","r",stdin);
        freopen("PATH.out","w",stdout);
    }
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
        cin>>a[i];
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
        update(1,1,n,st[i],a[i]);
    while(q--)
    {
        cin>>truy>>s;
        if(truy==1)
        {
            cin>>x;
            update(1,1,n,st[s],x);
        }
        else cout<<get(1,1,n,st[s],en[s])<<'\n';
    }
    return 0;
}
