#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,m;
ll d[100002];
vector<pii> v[100002];
void van_dijk(int s)
{
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    fill(d,d+n+1,1e18);
    pq.push({0,s});
    d[s]=0;
    while(!pq.empty())
    {
        pll p=pq.top();
        pq.pop();
        if(p.fi>d[p.se]) continue;
        for(pii j:v[p.se])
        {
            int u=j.fi,v=j.se;
            if(d[u]>d[p.se]+v)
            {
                d[u]=d[p.se]+v;
                pq.push({d[u],u});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0,truy,x,y,z;i<m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});
    }
    van_dijk(1);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';
    return 0;
}
