#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int mod=1000000007;
int n;
char a[1002][1002];
ll dp[1002][1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    dp[1][1]=(a[1][1]!='*');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if((i!=1||j!=1)&&a[i][j]!='*')
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    cout<<dp[n][n];
    return 0;
}
