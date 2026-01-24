#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll,ll>
using namespace std;
int n,q,truy,l,r;
pll st[800002];
pll ghep(pll a,pll b)
{
    pll kq;
    kq.fi=a.fi+b.fi;
    kq.se=max(a.se,a.fi+b.se);
    return kq;
}
void update(int i,int l,int r,int vt,int gt)
{
    if(l==r)
    {
        st[i]={gt,max(gt,0)};
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    st[i]=ghep(st[i*2],st[i*2+1]);
}
pll get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return {0,-1e18};
    if(l>=a&&r<=b) return st[i];
    int mid=l+r>>1;
    return ghep(get(i<<1,l,mid,a,b),get(i<<1|1,mid+1,r,a,b));
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
        cin>>truy>>l>>r;
        if(truy==1) update(1,1,n,l,r);
        else cout<<get(1,1,n,l,r).se<<'\n';
    }
    return 0;
}
