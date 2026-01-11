#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define plii pair<ll,pair<int,int> >
using namespace std;
int n,m,k;
ll d[2][100002];
vector<pii> v[100002];
void van_dijk(int s)
{
    priority_queue<plii,vector<plii>,greater<plii> > pq;
    for(int i=0;i<=k;i++)
        fill(d[i]+1,d[i]+n+1,1e18);
    for(int i=0;i<=k;i++)
    d[i][s]=0;
    pq.push({0,{s,0}});
    while(!pq.empty())
    {
        plii p=pq.top();
        pq.pop();
        if(p.fi>d[p.se.se][p.se.fi]) continue;
        for(pii j:v[p.se.fi])
        {
            int u=j.fi,v=j.se;
            for(int kaka=p.se.se;kaka<=k;kaka++)
            {
                ll concakkk=v/(1<<(kaka-p.se.se));
                if(d[kaka][u]>d[p.se.se][p.se.fi]+concakkk)
                {
                    pq.push({d[kaka][u]=d[p.se.se][p.se.fi]+concakkk,{u,kaka}});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    k=1;
    for(int i=0,x,y,z;i<m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});
    }
    van_dijk(1);
    cout<<d[k][n];
    return 0;
}
