#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,q,up[31][200002],x,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        up[0][i]=x;
    }
    for(int k=1;k<31;k++)
        for(int i=1;i<=n;i++)
        up[k][i]=up[k-1][up[k-1][i]];
    while(q--)
    {
        cin>>x>>k;
        for(int cc=30;cc>=0;cc--)
            if((k>>cc)&1) x=up[cc][x];
        cout<<x<<'\n';
    }
    return 0;
}
