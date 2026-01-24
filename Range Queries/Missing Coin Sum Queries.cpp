#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    ll sum;
    int l,r;
};
int n,q,nt,l,r,root[200002];
cc st[200002*30];
pair<ll,int> a[200002];
int update(int i,int l,int r,int vt,int gt)
{
    int cur=++nt;
    st[cur]=st[i];
    st[cur].sum+=gt;
    if(l==r) return cur;
    int mid=l+r>>1;
    if(vt<=mid) st[cur].l=update(st[i].l,l,mid,vt,gt);
    else st[cur].r=update(st[i].r,mid+1,r,vt,gt);
    return cur;
}
ll get(int i,int l,int r,int a,int b)
{
    if(!i||r<a||l>b) return 0;
    if(l>=a&&r<=b) return st[i].sum;
    int mid=l+r>>1;
    return get(st[i].l,l,mid,a,b)+get(st[i].r,mid+1,r,a,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("gift.inp","r")){
        freopen("gift.inp","r",stdin);
        freopen("gift.out","w",stdout);
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        root[i]=update(root[i-1],1,n,a[i].se,a[i].fi);
    while(q--)
    {
        cin>>l>>r;
        ll cur=0;
        while(true)
        {
            int k=upper_bound(a+1,a+n+1,make_pair(cur+1,n+1))-a-1;
            ll s=get(root[k],1,n,l,r);
            if(s<=cur) break;
            cur=s;
        }
        cout<<cur+1<<'\n';
    }
    return 0;
}
