#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll,ll>
using namespace std;
int n,q,l,r,mx,up[21][1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x,y;i<=n;i++)
    {
        cin>>x>>y;
        mx=max(mx,y);
        up[0][y]=max(up[0][y],x);
    }
    for(int i=1;i<=mx;i++)
        up[0][i]=max(up[0][i],up[0][i-1]);
    for(int k=1;k<21;k++)
        for(int i=1;i<=mx;i++)
        up[k][i]=up[k-1][up[k-1][i]];
    while(q--)
    {
        cin>>l>>r;
        int dem=0;
        for(int k=20;k>=0;k--)
            if(up[k][r]>=l)
        {
            dem+=(1<<k);
            r=up[k][r];
        }
        cout<<dem<<'\n';
    }
    return 0;
}
