#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,st[800002];
void update(int i,int l,int r,int x,int y)
{
    if(l==r)
    {
        st[i]+=y;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)
        update(i*2,l,mid,x,y);
    else update(i*2+1,mid+1,r,x,y);
    st[i]=max(st[i*2],st[i*2+1]);
}
int finds(int i,int l,int r,int k)
{
    if(st[i]<k) return 0;
    if(l==r) return l;
    int mid=l+r>>1;
    if(st[i<<1]>=k) return finds(i<<1,l,mid,k);
    else return finds(i<<1|1,mid+1,r,k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        update(1,1,n,i,x);
    }
    for(int i=1,x;i<=m;i++)
    {
        cin>>x;
        int vt=finds(1,1,n,x);
        cout<<vt<<' ';
        if(vt)
        update(1,1,n,vt,-x);
    }
    return 0;
}
