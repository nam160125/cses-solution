#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int dx[]={-1,-2,-2,-1,1,2,2,1};
const int dy[]={-2,-1,1,2,2,1,-1,-2};
int d[1002][1002],n;
queue<pair<int,int> >q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        fill(d[i]+1,d[i]+n+1,2e9);
    d[1][1]=0;
    q.push({1,1});
    while(!q.empty())
    {
        auto [i,j]=q.front();
        q.pop();
        for(int k=0;k<8;k++)
        {
            int u=i+dx[k],v=j+dy[k];
            if(u>0&&v>0&&u<=n&&v<=n&&d[u][v]>d[i][j]+1)
            {
                d[u][v]=d[i][j]+1;
                q.push({u,v});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<d[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
