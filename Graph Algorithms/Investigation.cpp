#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int mod=1000000007;
struct cc
{
    ll x,y,z,t;
};
int n,m;
cc d[100002];
vector<pii> v[100002];
void van_dijk(int s)
{
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    for(int i=1;i<=n;i++)
    d[i]={1000000000000000000,0,0,0};
    pq.push({0,s});
    d[s]={0,1,1,1};
    while(!pq.empty())
    {
        pll p=pq.top();
        pq.pop();
        if(p.fi>d[p.se].x) continue;
        for(pii j:v[p.se])
        {
            int u=j.fi,v=j.se;
            if(d[u].x>d[p.se].x+v)
            {
                d[u].x=d[p.se].x+v;
                d[u].y=d[p.se].y;
                d[u].z=d[p.se].z+1;
                d[u].t=d[p.se].t+1;
                pq.push({d[u].x,u});
            }
            else if(d[u].x==d[p.se].x+v)
            {
                d[u].y=(d[u].y+d[p.se].y)%mod;
                d[u].z=min(d[u].z,d[p.se].z+1);
                d[u].t=max(d[u].t,d[p.se].t+1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0,x,y,z;i<m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});
    }
    van_dijk(1);
    cout<<d[n].x<<' '<<d[n].y<<' '<<d[n].z-1<<' '<<d[n].t-1;
    return 0;
}
