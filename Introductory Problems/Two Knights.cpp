#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c(ll k)
{
    ll c1=(k*k*(k*k-1))/2;
    ll c2=4*(k-1)*(k-2);
    return c1-c2;
}
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
     cin>>n;
     for(ll i=1;i<=n;i++)
        cout<<c(i)<<'\n';
    return 0;
}
