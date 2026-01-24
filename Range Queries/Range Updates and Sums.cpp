#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,a[200002],truy,u,v,x;
struct node
{
    ll gt,ganh1,ganh2;
};
node st[800002];
void build(int i,int l,int r)
{
    if(l==r)
    {
        st[i].gt=a[l];
        return;
    }
    int mid=l+r>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    st[i].gt=st[i<<1].gt+st[i<<1|1].gt;
}
void push1(int i,int l,int r)
{
    if(st[i].ganh1!=0)
    {
        st[i].gt+=(r-l+1)*st[i].ganh1;
        if(l!=r){
        st[i<<1].ganh1+=st[i].ganh1;
        st[i<<1|1].ganh1+=st[i].ganh1;
        }
        st[i].ganh1=0;
    }
}
void push2(int i,int l,int r)
{
    if(st[i].ganh2!=0)
    {
        st[i].gt=(r-l+1)*st[i].ganh2;
        if(l!=r)
        {
            st[i<<1].ganh2=st[i].ganh2;
            st[i<<1|1].ganh2=st[i].ganh2;
            st[i<<1].ganh1=0;
            st[i<<1|1].ganh1=0;
        }
        st[i].ganh2=0;
    }
}
void update1(int i,int l,int r,int a,int b,int gt)
{
    push2(i,l,r);
    push1(i,l,r);
    if(r<a||l>b) return;
    if(l>=a&&r<=b)
    {
        st[i].ganh1+=gt;
        push1(i,l,r);
        return;
    }
    int mid=l+r>>1;
    update1(i<<1,l,mid,a,b,gt);
    update1(i<<1|1,mid+1,r,a,b,gt);
    st[i].gt=st[i<<1].gt+st[i<<1|1].gt;
}
void update2(int i,int l,int r,int a,int b,int gt)
{
    push2(i,l,r);
    push1(i,l,r);
    if(r<a||l>b) return;
    if(l>=a&&r<=b)
    {
        st[i].ganh2=gt;
        push2(i,l,r);
        return;
    }
    int mid=l+r>>1;
    update2(i<<1,l,mid,a,b,gt);
    update2(i<<1|1,mid+1,r,a,b,gt);
    st[i].gt=st[i<<1].gt+st[i<<1|1].gt;
}
ll get(int i,int l,int r,int a,int b)
{
    push2(i,l,r);
    push1(i,l,r);
    if(r<a||l>b) return 0;
    if(l>=a&&r<=b)
        return st[i].gt;
    int mid=l+r>>1;
    return get(i<<1,l,mid,a,b)+get(i<<1|1,mid+1,r,a,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        cin>>truy>>u>>v;
        if(truy==1)
        {
            cin>>x;
            update1(1,1,n,u,v,x);
        }
        else if(truy==2)
        {
            cin>>x;
            update2(1,1,n,u,v,x);
        }
        else cout<<get(1,1,n,u,v)<<'\n';
    }
    return 0;
}
