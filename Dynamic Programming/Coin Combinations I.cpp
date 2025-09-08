#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x,a[102];
ll f[1000002];
const int mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        f[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=n;j++)
            if(i>=a[j])
            f[i]=(f[i]+f[i-a[j]])%mod;
    }
    cout<<f[x];
    return 0;
}
