#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,st[800002],q,c1,c2,in;
void update(int i,int l,int r,int x,int y)
{
    if(l==r)
    {
        st[i]=y;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)
        update(i*2,l,mid,x,y);
    else update(i*2+1,mid+1,r,x,y);
    st[i]=min(st[i*2],st[i*2+1]);
}
int get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return 2e9;
    if(l>=a&&r<=b)
    {
        return st[i];
    }
    int mid=l+r>>1;
    return min(get(i*2,l,mid,a,b),get(i*2+1,mid+1,r,a,b));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        update(1,1,n,i,x);
    }
    while(q--)
    {
        cin>>in>>c1>>c2;
        if(in==1)
            update(1,1,n,c1,c2);
        else cout<<get(1,1,n,c1,c2)<<'\n';
    }
    return 0;
}
