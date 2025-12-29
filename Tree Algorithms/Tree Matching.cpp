#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,dp[2][200002];
vector<int> v[200002];
void dfs(int i,int par)
{
    dp[0][i]=0;
    dp[1][i]=-2e9;
    for(int j:v[i])
    {
        if(j==par) continue;
        dfs(j,i);
        dp[0][i]+=max(dp[1][j],dp[0][j]);
        dp[1][i]=max(dp[1][i],min(dp[0][j]-dp[1][j],0));
    }
    dp[1][i]+=dp[0][i];
    dp[1][i]++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    cout<<max(dp[1][1],dp[0][1]);
    return 0;
}
