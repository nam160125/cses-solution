#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    ll t,pre,suf,kq;
};
int n,q,truy,l,r;
cc st[800002];
cc ghep(cc a,cc b)
{
    cc kq;
    kq.t=a.t+b.t;
    kq.pre=max(a.pre,a.t+b.pre);
    kq.suf=max(b.suf,b.t+a.suf);
    kq.kq=max({a.kq,b.kq,a.suf+b.pre});
    return kq;
}
void update(int i,int l,int r,int vt,int gt)
{
    if(l==r)
    {
        st[i]={gt,gt,gt,gt};
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    st[i]=ghep(st[i*2],st[i*2+1]);
}
cc get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return {0,-1000000000000000000,-1000000000000000000,-1000000000000000000};
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
        cin>>l>>r;
        cout<<max(0ll,get(1,1,n,l,r).kq)<<'\n';
    }
    return 0;
}
