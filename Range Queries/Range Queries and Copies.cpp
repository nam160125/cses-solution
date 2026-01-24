#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
struct cc
{
    int l,r;
    ll sum;
};
int n,q,nt,truy,k,a,x,A[200002];
cc st[200002*27];
vector<int> root;
int newNode(ll s,int l,int r)
{
    st[++nt]={l,r,s};
    return nt;
}
int build(int l,int r)
{
    if(l==r) return newNode(A[l],0,0);
    int mid=l+r>>1;
    int le=build(l,mid),ri=build(mid+1,r);
    return newNode(st[le].sum+st[ri].sum,le,ri);
}
int update(int i,int l,int r,int vt,int gt)
{
    if(l==r) return newNode(gt,0,0);
    int mid=l+r>>1;
    if(vt<=mid)
    {
        int le=update(st[i].l,l,mid,vt,gt);
        return newNode(st[le].sum+st[st[i].r].sum,le,st[i].r);
    }
    else
    {
        int ri=update(st[i].r,mid+1,r,vt,gt);
        return newNode(st[st[i].l].sum+st[ri].sum,st[i].l,ri);
    }
}
ll get(int i,int l,int r,int a,int b)
{
    if(i==0||r<a||l>b) return 0;
    if(l>=a&&r<=b) return st[i].sum;
    int mid=l+r>>1;
    return get(st[i].l,l,mid,a,b)+get(st[i].r,mid+1,r,a,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    root.push_back(build(1,n));
    cout<<root.back()<<'\n';
    while(q--)
    {
        cin>>truy;
        if(truy==1)
        {
            cin>>k>>a>>x;
            root[k-1]=update(root[k-1],1,n,a,x);
        }
        else if(truy==2)
        {
            cin>>k>>a>>x;
            cout<<get(root[k-1],1,n,a,x)<<'\n';
        }
        else
        {
            cin>>k;
            root.push_back(root[k-1]);
        }
    }
    return 0;
}
