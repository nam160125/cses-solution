#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int mod=1000000007;
int n,m,deg[100002];
ll way[100002];
bool kt[100002];
vector<int> v[100002],topo;
void tspo()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(deg[i]==0) q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int j:v[u])
            if(--deg[j]==0) q.push(j);
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
        deg[y]++;
        v[x].push_back(y);
    }
    tspo();
    way[1]=1;
    for(int i:topo)
        for(int j:v[i])
        way[j]=(way[i]+way[j])%mod;
    cout<<way[n];
    return 0;
}
