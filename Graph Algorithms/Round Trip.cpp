#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m;
vector<int> v[1000002],kq,tame;
bool kt[1000002],stop;
void dfs(int i,int u)
{
    if(stop) return;
    kt[i]=true;
    kq.push_back(i);
    for(int j:v[i])
    {
        if(stop) return;
        if(j==u) continue;
        if(!kt[j])
        {
            dfs(j,i);
            if(kq.size()>0)
            kq.pop_back();
        }
        else if(kq.size()>2)
        {
            kq.push_back(j);
            stop=1;
            tame=kq;
            return;
        }
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
        if(!kt[i])
            dfs(i,-1);
    }
    reverse(tame.begin(),tame.end());
    while(tame[tame.size()-1]!=tame[0]&&tame.size()>0)
        tame.pop_back();
    if(tame.size()==0) {cout<<"IMPOSSIBLE";return 0;}
    cout<<tame.size()<<'\n';
    for(int i=tame.size()-1;i>=0;i--)
        cout<<tame[i]<<' ';
    return 0;
}
