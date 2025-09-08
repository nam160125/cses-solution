#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[1000000];
int n;
const int mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=min(6,i);j++)
    {
        f[i]=(f[i]+f[i-j])%mod;
    }
    cout<<f[n];
    return 0;
}
