#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,k,sz[200002];
vector<int> v[200002];
bool kt[200002];
ll dem,c[200002];
void dfs(int i,int p)
{
    sz[i]=1;
    for(int j:v[i])
    {
        if(j==p||kt[j]) continue;
        dfs(j,i);
        sz[i]+=sz[j];
    }
}
int findcen(int i,int p)
{
    dfs(i,-1);
    int tong=sz[i];
    bool moved=true;
    while(moved)
    {
        moved=false;
        for(int j:v[i])
        {
            if(j==p||kt[j]) continue;
            if(sz[j]*2>tong)
            {
                p=i;
                i=j;
                moved=true;break;
            }
        }
    }
    return i;
}
void update(int i,int p,int dep,vector<int> &dist)
{
    if(dep>k) return;
    dist.push_back(dep);
    for(int j:v[i]) if(j!=p&&kt[j]==false)
        update(j,i,dep+1,dist);
}
void solve(int i)
{
    int cen=findcen(i,-1);
    kt[cen]=true;
    fill(c,c+min(k,sz[i])+1,0);
    c[0]=1;
    for(int j:v[cen])
    {
        if(kt[j]) continue;
        vector<int> dist;
        update(j,cen,1,dist);
        for(int d:dist){
            if(k-d>=0&&k-d<=min(k,sz[i]))
            dem+=c[k-d];
        }
        for(int d:dist) if(d<=min(k,sz[i])) c[d]++;
    }
    for(int j:v[cen])
        if(kt[j]==false) solve(j);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("kingdom.inp","r")){
        freopen("kingdom.inp","r",stdin);
        freopen("kingdom.out","w",stdout);
    }
    cin>>n>>k;
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve(1);cout<<dem;
    return 0;
}
