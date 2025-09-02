#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],vt[200002],n,m,x,y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int dem=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vt[a[i]]=i;
    }
    for(int i=1;i<n;i++)
        if(vt[i+1]<vt[i]) dem++;
    while(m--)
    {
        cin>>x>>y;
        if(x>y) swap(x,y);
        swap(vt[a[x]],vt[a[y]]);
        if(vt[a[x]]>vt[a[y]-1]&&vt[a[y]]<vt[a[y]-1]) dem++;
        if(vt[a[y]]<vt[a[x]-1]&&vt[a[x]]>vt[a[x]-1]) dem--;
        if(vt[a[y]]<vt[a[x]+1]&&vt[a[x]+1]<vt[a[x]]) dem++;
        if(vt[a[x]]>vt[a[y]+1]&&vt[a[y]+1]>vt[a[y]]) dem--;
        if(a[x]-a[y]==1) dem--;
        else if(a[x]-a[y]==-1) dem++;

        cout<<dem<<'\n';
        swap(a[x],a[y]);
    }
    return 0;
}
