#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,l,r,st[18][200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        st[0][i]=x;
    }
    for(int k=1;k<18;k++)
        for(int i=1;i+(1<<k)-1<=n;i++)
        st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
    while(q--)
    {
        cin>>l>>r;
        int lg=__lg(r-l+1);
        cout<<min(st[lg][l],st[lg][r-(1<<lg)+1])<<'\n';
    }
    return 0;
}
