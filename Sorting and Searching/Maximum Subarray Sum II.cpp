#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a,b;
ll f[200002],st[800002],mx=-1e18;
void update(int i,int l,int r,int vt,ll gt)
{
    if(l==r)
    {
        st[i]=f[l];
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    st[i]=min(st[i<<1],st[i<<1|1]);
}
ll get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return 2e18;
    if(l>=a&&r<=b) return st[i];
    int mid=l+r>>1;
    return min(get(i<<1,l,mid,a,b),get(i<<1|1,mid+1,r,a,b));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>a>>b;
    update(1,0,n,0,0);
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        f[i]=f[i-1]+x;
        update(1,0,n,i,f[i]);
    }
    for(int i=a;i<=n;i++)
        mx=max(mx,f[i]-get(1,0,n,max(0,i-b),i-a));
    cout<<mx;
    return 0;
}
