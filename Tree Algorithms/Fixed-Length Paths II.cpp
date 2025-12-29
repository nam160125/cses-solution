#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,k1,k2,sz[200002],bit[200002];
vector<int> v[200002];
bool kt[200002];
ll dem;
void update2(int i,int gt,int lim)
{
    for(i;i<=lim;i+=i&(-i))
        bit[i]+=gt;
}
int get(int i)
{
    int dem=0;
    for(i;i>0;i-=i&(-i))
        dem+=bit[i];
    return dem;
}
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
    if(dep>k2) return;
    dist.push_back(dep);
    for(int j:v[i]) if(j!=p&&kt[j]==false)
        update(j,i,dep+1,dist);
}
void solve(int i)
{
    int cen=findcen(i,-1);
    kt[cen]=true;
    int mxd=0;
    vector<vector<int>> all;
    for(int j:v[cen])
    {
        if(kt[j]) continue;
        vector<int> dist;
        update(j,cen,1,dist);
        for(int d:dist){
            mxd=max(mxd,d);
        }
        all.push_back(move(dist));
    }
    mxd++;
    fill(bit,bit+mxd+1,0);
    update2(1,1,mxd);
    for(auto &ds:all){
        for(int d:ds){
            int sm=k1-d;
            int sm2=k2-d;
            if(sm2<0) continue;
            if(sm<0) sm=0;
            sm++;sm2++;
            if(sm>mxd) continue;
            if(sm2>mxd) sm2=mxd;
            dem+=get(sm2)-(sm==0?0:get(sm-1));
        }
        for(int d:ds) update2(d+1,1,mxd);
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
    cin>>n>>k1>>k2;
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve(1);
    cout<<dem;
    return 0;
}
