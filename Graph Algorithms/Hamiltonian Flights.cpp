#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
const int mod=1000000007;
int n,m;
ll dp[1<<21][25];
vector<int> v[25];
void bfs()
{
    dp[1][0]=1;
    queue<pii> q;
    q.push({1,0});
    while(!q.empty())
    {
        auto [ma,u]=q.front();
        q.pop();
        for(int j:v[u])
            if((ma&(1<<j))==0)
            {
                dp[ma|(1<<j)][j]=(dp[ma|(1<<j)][j]+dp[ma][u])%mod;
                q.push({(ma|(1<<j)),j});
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
    }
    bfs();
    cout<<dp[(1<<n)-1][n-1];
    return 0;
}
