#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll dem=1;
    for(int i=1;i<=n;i++)
    {
        dem=((dem%mod)*(2%mod))%mod;
    }
    cout<<dem;
    return 0;
}
