#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int n,m,vt1,vt2,vt3,vt4;
bool kt[1002][1002];
char xxx;
int d[1002][1002];
pair<int,int> truy[1002][1002];
bool ck(int a,int b)
{
    return (a>0&&b>0&&a<=n&&b<=m&&kt[a][b]==false);
}
string st;
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
                if(d[u][v]>d[cc.fi][cc.se]+1){
                d[u][v]=d[cc.fi][cc.se]+1;
                truy[u][v]={cc.fi,cc.se};
                }
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
        for(int j=1;j<=m;j++)
    {
        cin>>xxx;
        if(xxx=='#') kt[i][j]=true;
        else if(xxx=='A') {vt1=i;vt2=j;}
        else if(xxx=='B') {vt3=i;vt4=j;}
        d[i][j]=1000000000;
    }
    d[vt1][vt2]=0;
    bfs(vt1,vt2);
    if(d[vt3][vt4]==1000000000) {cout<<"NO";return 0;}
    cout<<"YES\n";
    cout<<d[vt3][vt4]<<'\n';
    while(truy[vt3][vt4]!=make_pair(0,0))
        {
            int cc1=truy[vt3][vt4].fi;
            int cc2=truy[vt3][vt4].se;
            if(vt3-cc1==-1&&vt4-cc2==0) st.push_back('U');
            else if(vt3-cc1==1&&vt4-cc2==0) st.push_back('D');
            else if(vt3-cc1==0&&vt4-cc2==-1) st.push_back('L');
            else if(vt3-cc1==0&&vt4-cc2==1)st.push_back('R');
            vt3=cc1;
            vt4=cc2;
        }
    reverse(st.begin(),st.end());
    cout<<st;
    return 0;
}
