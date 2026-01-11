#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,mx[2002],my[2002],dem,a,b,x,y,chill;
vector<int> v[2002];
bool vis[2002];
bool dfs(int i)
{
    for(int j:v[i])
    {
        if(vis[j]) continue;
        vis[j]=true;
        if(my[j]==0||dfs(my[j]))
        {
            my[j]=i;
            mx[i]=j;
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>chill;
    while(chill--){
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=a;i++)
    {
        fill(vis,vis+a+b+1,false);
        if(dfs(i)) dem++;
    }
    cout<<dem<<'\n';
    for(int i=1;i<=a;i++)
        if(mx[i]>0)
        cout<<i<<' '<<mx[i]<<'\n';
    return 0;
}
