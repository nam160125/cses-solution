#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n;
ll dp[5002][5002];
ll f[5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        f[i]=f[i-1]+x;
    }
    for(int l=1;l<=n;l++)
        for(int i=1;i<=n-l+1;i++)
    {
        int j=i+l-1;
        if(i==j)
            dp[i][j]=f[j]-f[i-1];
        else
            dp[i][j]=f[j]-f[i-1]-min(dp[i+1][j],dp[i][j-1]);
    }
    cout<<dp[1][n];
    return 0;
}
