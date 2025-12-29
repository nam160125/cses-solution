#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n;
ll sz[200002],dp[200002],mx;
vector<int> v[200002];
void dfs(int i,int p,int dep)
{
    sz[i]=1;
    dp[1]+=dep;
    for(int j:v[i])
    {
        if(j==p) continue;
        dfs(j,i,dep+1);
        sz[i]+=sz[j];
    }
}
void dfs2(int i,int p)
{
    for(int j:v[i])
    {
        if(j==p) continue;
        dp[j]=dp[i]+n-2*sz[j];
        dfs2(j,i);
    }
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
    dfs(1,-1,0);
    dfs2(1,-1);
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<' ';
    return 0;
}
