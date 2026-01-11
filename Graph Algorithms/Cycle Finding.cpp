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
int n,m,start,truy[2502];
ll d[2502];
vector<int> an;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].u>>a[i].v>>a[i].gt;
    for(int step=0;step<n;step++)
    {
        start=0;
        for(int i=1;i<=m;i++)
            if(d[a[i].v]>d[a[i].u]+a[i].gt){
                d[a[i].v]=d[a[i].u]+a[i].gt;
                truy[a[i].v]=a[i].u;
                start=a[i].v;
            }
    }
    if(start==0) {cout<<"NO";return 0;}
    for(int i=0;i<n;i++)
        start=truy[start];
    int v=start;
    do
    {
        an.push_back(v);
        v=truy[v];
    }
    while(v!=-1&&v!=start);
    an.push_back(v);
    cout<<"YES\n";
    for(int i=an.size()-1;i>=0;i--) cout<<an[i]<<' ';
    return 0;
}
