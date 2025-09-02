#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
const int mod=1000000007;
int n;
ll dem=1;
unordered_map<int,int> c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        c[x]++;
    }
    for(auto x:c)
        dem=(dem*(x.se+1))%mod;
    cout<<dem-1;
    return 0;
}
