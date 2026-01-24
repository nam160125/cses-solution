#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,x,y,u,v,f[1002][1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            f[i][j]=(ch=='*');
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
    while(q--)
    {
        cin>>x>>y>>u>>v;
        cout<<f[u][v]-f[x-1][v]-f[u][y-1]+f[x-1][y-1]<<'\n';
    }
    return 0;
}
