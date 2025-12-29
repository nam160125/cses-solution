#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,q,up[19][200002],x,k;
vector<int> v[200002];
void dfs(int i,int p)
{
    up[0][i]=p;
    for(int k=1;k<=18;k++)
        up[k][i]=up[k-1][up[k-1][i]];
    for(int j:v[i])
        if(j!=p) dfs(j,i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=2,x;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    dfs(1,0);
    while(q--)
    {
        cin>>x>>k;
        for(int i=18;i>=0;i--)
            if((1<<i)<=k)
            {
                x=up[i][x];
                k-=(1<<i);
            }
        cout<<(x==0?-1:x)<<'\n';
    }
    return 0;
}
