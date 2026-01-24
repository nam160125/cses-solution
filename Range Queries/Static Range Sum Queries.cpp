#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,l,r;
ll f[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        f[i]=f[i-1]+x;
    }
    while(q--)
    {
        cin>>l>>r;
        cout<<f[r]-f[l-1]<<'\n';
    }
    return 0;
}
