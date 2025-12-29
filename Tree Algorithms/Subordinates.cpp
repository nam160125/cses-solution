#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,dp[200002];
vector<int> v[200002];
void dfs(int i)
{
    for(int j:v[i])
    {
        dfs(j);
        dp[i]+=dp[j]+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=2,x;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<' ';
    return 0;
}
