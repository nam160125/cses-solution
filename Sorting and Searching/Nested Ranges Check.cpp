#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    int u,v,id;
};
bool cmp(cc a,cc b)
{
    if(a.u==b.u) return a.v>b.v;
    return a.u<b.u;
}
int n,an[200002],an2[200002],mx;
cc p[200002];
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].u>>p[i].v;
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(p[i].v<=mx)
            an2[p[i].id]=1;
        else mx=p[i].v;
    mx=2e9;
    for(int i=n;i>=1;i--)
        if(p[i].v>=mx)
            an[p[i].id]=1;
        else mx=p[i].v;
    for(int i=1;i<=n;i++)
        cout<<an[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++)
        cout<<an2[i]<<' ';
    return 0;
}
