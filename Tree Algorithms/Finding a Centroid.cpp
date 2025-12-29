#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,dp[200002];
vector<int> v[200002];
void dfs(int i,int p)
{
    for(int j:v[i])
    {
        if(j==p) continue;
        dfs(j,i);
        dp[i]+=dp[j];
    }
    dp[i]++;
}
int finds(int i,int p)
{
    for(int j:v[i])
        if(j!=p)
            if(dp[j]*2>n)
                return finds(j,i);
    return i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0,x,y;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    cout<<finds(1,-1);
    return 0;
}
