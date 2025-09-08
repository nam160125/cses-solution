#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int mod=1000000007;
int n,m;
ll dp[102][100002],dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        if(x==0)
            if(i==1)
            for(int j=1;j<=m;j++)
                dp[j][i]=1;
            else
                for(int j=1;j<=m;j++)
            dp[j][i]=(dp[j][i-1]+(j>0?dp[j-1][i-1]:0)+dp[j+1][i-1])%mod;
        else if(i==1)
                dp[x][i]=1;
            else
            dp[x][i]=((x>0?dp[x-1][i-1]:0)+dp[x][i-1]+dp[x+1][i-1])%mod;
    }
        for(int j=1;j<=m;j++)
            dem=(dem+dp[j][n])%mod;
    cout<<dem;
    return 0;
}
