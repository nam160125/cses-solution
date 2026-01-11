#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
bool kt[100002];
vector<int> v[100002],kq;
int n,m,dem;
void dfs(int i)
{
    kt[i]=1;
    for(int i:v[i])
    {
        if(kt[i]==false)
        dfs(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(kt[i]==false)
        {
            dfs(i);
            kq.push_back(i);
        }
    }
    cout<<kq.size()-1<<'\n';
    for(int i=0;i<kq.size()-1;i++)
        cout<<kq[i]<<' '<<kq[i+1]<<'\n';
    return 0;
}
