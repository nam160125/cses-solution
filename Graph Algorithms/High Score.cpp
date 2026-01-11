#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
struct canh
{
    int u,v,gt;
};
canh a[5002];
int n,m;
ll d[2502];
bool kt[2502];
vector<int> v[2502];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].gt;
        v[a[i].u].push_back(a[i].v);
        a[i].gt=-a[i].gt;
    }
    fill(d+1,d+n+1,1e18);
    d[1]=0;
    for(int step=0;step<n;step++)
    {
        for(int i=1;i<=m;i++)
            if(d[a[i].u]<1e18&&d[a[i].v]>d[a[i].u]+a[i].gt)
            d[a[i].v]=d[a[i].u]+a[i].gt;
    }
    for(int step=0;step<n;step++)
    {
        for(int i=1;i<=m;i++)
            if(d[a[i].u]<1e18&&d[a[i].v]>d[a[i].u]+a[i].gt)
            {
                kt[a[i].v]=true;
                q.push(a[i].v);
            }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j:v[u])
            if(kt[j]==false)
            {
                kt[j]=true;
                q.push(j);
            }
    }
    if(kt[n]) cout<<-1;
    else
    cout<<-d[n];
    return 0;
}
