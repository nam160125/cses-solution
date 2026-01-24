#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int n,q,truy,l,r;
pii st[800002];
void update(int i,int l,int r,int vt,int gt)
{
    if(l==r)
    {
        st[i]={gt-l,gt+l};
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    st[i].fi=min(st[i<<1].fi,st[i<<1|1].fi);
    st[i].se=min(st[i<<1].se,st[i<<1|1].se);
}
pii get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return {2e9,2e9};
    if(l>=a&&r<=b) return st[i];
    int mid=l+r>>1;
    pii le=get(i<<1,l,mid,a,b),ri=get(i<<1|1,mid+1,r,a,b);
    return {min(le.fi,ri.fi),min(le.se,ri.se)};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        update(1,1,n,i,x);
    }
    while(q--)
    {
        cin>>truy;
        if(truy==1)
        {
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else
        {
            cin>>l;
            cout<<min(get(1,1,n,1,l).fi+l,get(1,1,n,l,n).se-l)<<'\n';
        }
    }
    return 0;
}
