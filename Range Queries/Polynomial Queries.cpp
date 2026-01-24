#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,a[200002],truy,u,v;
struct node
{
    ll gt,ga1,ga2;
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
void push(int i,int l,int r)
{
    st[i].gt+=st[i].ga1*(r-l+1)+st[i].ga2*(r-l+2)*(r-l+1)/2;
    int mid=l+r>>1;
    if(l!=r)
    {
        st[i<<1].ga1+=st[i].ga1;
        st[i<<1].ga2+=st[i].ga2;
        st[i<<1|1].ga1+=st[i].ga1+(mid+1-l)*st[i].ga2;
        st[i<<1|1].ga2+=st[i].ga2;
    }
    st[i].ga1=st[i].ga2=0;
}
void update(int i,int l,int r,int a,int b)
{
    push(i,l,r);
    if(r<a||l>b) return;
    if(l>=a&&r<=b)
    {
        st[i].ga1+=l-a;
        st[i].ga2++;
        push(i,l,r);
        return;
    }
    int mid=l+r>>1;
    update(i<<1,l,mid,a,b);
    update(i<<1|1,mid+1,r,a,b);
    st[i].gt=st[i<<1].gt+st[i<<1|1].gt;
}
ll get(int i,int l,int r,int a,int b)
{
    push(i,l,r);
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
            update(1,1,n,u,v);
        else cout<<get(1,1,n,u,v)<<'\n';
    }
    return 0;
}
