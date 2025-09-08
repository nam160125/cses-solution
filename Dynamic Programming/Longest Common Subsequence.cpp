#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,m,dp[1002][1002],a[1002],b[1002],cak;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j])
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<'\n';
    cak=dp[n][m];
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            v.push_back(a[i]);
            i--;j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]) i--;
        else j--;
    }
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<' ';
    return 0;
}
