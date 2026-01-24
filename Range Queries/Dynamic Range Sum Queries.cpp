#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,truy,x,y,a[200002];
ll bit[200002];
void update(int idx,int gt)
{
    ll diff=gt-a[idx];
    a[idx]=gt;
    while(idx<=n)
    {
        bit[idx]+=diff;
        idx+=idx&(-idx);
    }
}
ll get(int idx)
{
    ll dem=0;
    while(idx>0)
    {
        dem+=bit[idx];
        idx-=idx&(-idx);
    }
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        update(i,x);
    }
    while(q--)
    {
        cin>>truy>>x>>y;
        if(truy==1) update(x,y);
        else cout<<get(y)-get(x-1)<<'\n';
    }
    return 0;
}
