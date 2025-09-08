#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int mod=1000000007;
int n;
ll dp[250002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    dp[0]=1;
    for(int k=1;k<=n;k++)
        for(int tong=n*(n+1)/2;tong>=k;tong--)
        dp[tong]=(dp[tong]+dp[tong-k])%mod;
    if((n*(n+1)/2)%2!=0) cout<<0;
    else
    cout<<(dp[n*(n+1)/4]*(mod+1)/2)%mod;
    return 0;
}
