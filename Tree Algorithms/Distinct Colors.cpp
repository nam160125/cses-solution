#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,a[200002],d[200002];
vector<int> v[200002];
unordered_map<int,int> ccc;
void dfs(int i,int p,auto &cc)
{
    cc[a[i]]=1;
    for(int j:v[i])
    {
        if(j==p) continue;
        unordered_map<int,int> c;
        dfs(j,i,c);
        if(c.size()>cc.size()) swap(c,cc);
        for(auto x:c)
            cc[x.fi]=1;
    }
    d[i]=(int)cc.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("GRAPH.inp","r"))
    {
        freopen("GRAPH.inp","r",stdin);
        freopen("GRAPH.out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1,ccc);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';

    return 0;
}
