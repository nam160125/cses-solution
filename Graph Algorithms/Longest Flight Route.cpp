#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,deg[100002],par[100002];
int way[100002];
bool kt[100002];
vector<int> v[100002],v2[100002],topo,an;
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
        v2[y].push_back(x);
    }
    tspo();
    fill(way+1,way+n+1,-1e9);
    way[1]=1;
    for(int i:topo)
        for(int j:v2[i])
        if(way[i]<way[j]+1)
        {
            way[i]=way[j]+1;
            par[i]=j;
        }
    if(way[n]<1) cout<<"IMPOSSIBLE";
    else
    {
        for(n;n>0;n=par[n]) an.push_back(n);
        cout<<(int)an.size()<<'\n';
        for(int i=an.size()-1;i>=0;i--)
            cout<<an[i]<<' ';
    }
    return 0;
}
