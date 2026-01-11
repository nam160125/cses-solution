#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,m,k;
vector<pii> v[100002];
priority_queue<ll> d[100002];
vector<ll> an;
void van_dijk()
{
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    d[1].push(0);
    pq.push({0,1});
    while(!pq.empty())
    {
        auto [du,u]=pq.top();
        pq.pop();
        if(du>d[u].top()) continue;
        for(auto [v,w]:v[u])
        {
            ll cc=du+w;
            if(d[v].size()<k)
            {
                d[v].push(cc);
                pq.push({cc,v});
            }
            else if(cc<d[v].top())
            {
                d[v].pop();
                d[v].push(cc);
                pq.push({cc,v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});

    }
    van_dijk();
    while(!d[n].empty())
    {
        an.push_back(d[n].top());
        d[n].pop();
    }
    for(int i=an.size()-1;i>=0;i--) cout<<an[i]<<' ';
    return 0;
}
