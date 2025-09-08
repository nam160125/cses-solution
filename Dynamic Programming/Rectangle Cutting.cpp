#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m;
ll dp[502][502],dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fill(dp[i]+1,dp[i]+m+1,1e18);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(i==j) dp[i][j]=0;
    else
    {
        for(int k=1;k<j;k++)
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
        for(int k=1;k<i;k++)
            dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
    }
    cout<<dp[n][m];
    return 0;
}
