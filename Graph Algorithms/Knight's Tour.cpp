#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int dx[]={2,1,-1,-2,-2,-1,1,2};
const int dy[]={1,2,2,1,-1,-2,-2,-1};
int kt[9][9],x,y;
int cou(int i,int j)
{
    int dem=0;
    for(int k=0;k<8;k++)
    {
        int u=i+dx[k],v=j+dy[k];
        if(u>0&&v>0&&u<=8&&v<=8&&kt[u][v]==0)
            dem++;
    }
    return dem;
}
bool dfs(int i,int j,int step)
{
    kt[i][j]=step;
    if(step==64) return true;
    vector<tuple<int,int,int> > tiep;
    for(int k=0;k<8;k++)
    {
        int u=i+dx[k],v=j+dy[k];
        if(u>0&&v>0&&u<=8&&v<=8&&kt[u][v]==0)
            tiep.push_back({cou(u,v),u,v});
    }
    sort(tiep.begin(),tiep.end());
    for(auto [deg,u,v]:tiep)
        if(dfs(u,v,step+1))
        return true;
    kt[i][j]=0;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>x>>y;
    dfs(y,x,1);
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
            cout<<kt[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
