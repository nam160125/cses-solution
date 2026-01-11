#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int n,m;
bool kt[1003][1003];
char xxx;
bool ck(int a,int b)
{
    return (a>0&&b>0&&b<=m&&a<=n&&kt[a][b]==false);
}
int dem;
void bfs(int x,int y)
{
    queue<pair<int,int> > q;
    q.push({x,y});
    kt[x][y]=true;
    while(!q.empty())
    {
        pair<int,int> cc=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int u=cc.fi+dx[i];
            int v=cc.se+dy[i];
            if(ck(u,v))
            {
                kt[u][v]=true;
                q.push({u,v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
        cin>>xxx;
        if(xxx=='#') kt[i][j]=true;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(kt[i][j]==false)
    {
        bfs(i,j);
        dem++;
    }
    cout<<dem;
    return 0;
}
