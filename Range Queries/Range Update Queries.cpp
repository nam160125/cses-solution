#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,q,truy,l,r,x;
pll st[800002];
void push(int i,int l,int r)
{
    if(st[i].se!=0)
    {
        st[i].fi+=st[i].se;
        if(l!=r)
        {
            st[i<<1].se+=st[i].se;
            st[i<<1|1].se+=st[i].se;
        }
        st[i].se=0;
    }
}
void update(int i,int l,int r,int a,int b,int gt)
{
    push(i,l,r);
    if(r<a||l>b) return;
    if(l>=a&&r<=b)
    {
        st[i].se+=gt;
        push(i,l,r);
        return;
    }
    int mid=l+r>>1;
    update(i<<1,l,mid,a,b,gt);
    update(i<<1|1,mid+1,r,a,b,gt);
}
ll get(int i,int l,int r,int vt)
{
    push(i,l,r);
    if(l==r) return st[i].fi;
    int mid=l+r>>1;
    if(vt<=mid) return get(i<<1,l,mid,vt);
    else return get(i<<1|1,mid+1,r,vt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        update(1,1,n,i,i,x);
    }
    while(q--)
    {
        cin>>truy;
        if(truy==2)
        {
            cin>>x;
            cout<<get(1,1,n,x)<<'\n';
        }
        else
        {
            cin>>l>>r>>x;
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}
