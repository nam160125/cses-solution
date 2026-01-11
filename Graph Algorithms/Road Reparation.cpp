#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,ck,p[100002];
ll dem;
struct cc
{
    int x,y,z;
};
cc a[200002];
int finds(int u)
{
    return p[u]<0?u:p[u]=finds(p[u]);
}
bool cmp(cc a,cc b)
{
    return a.z<b.z;
}
bool soviet(int u,int v)
{
    int a=finds(u);
    int b=finds(v);
    if(a==b) return false;
    p[b]=a;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    fill(p+1,p+n+1,-1);
    for(int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(soviet(a[i].x,a[i].y)==false) continue;
        ck++;
        dem+=a[i].z;
        if(ck==n-1) break;
    }
    if(ck==n-1)
    cout<<dem;
    else cout<<"IMPOSSIBLE";
    return 0;
}
