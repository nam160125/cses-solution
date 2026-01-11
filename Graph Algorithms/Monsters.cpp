#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int n,m,d1[1002][1002],d2[1002][1002],step=-1;
char x;
bool kt[1002][1002],kt2[1002][1002];
pair<int,int> dau,truy[1002][1002];
queue<pair<int,int> > q1;
string st;
void bfs1()
{
    while(!q1.empty())
    {
        auto [u,v]=q1.front();
        q1.pop();
        for(int k=0;k<4;k++)
        {
            int newu=u+dx[k];
            int newv=v+dy[k];
            if(newu<=0||newv<=0||newu>n||newv>m||kt[newu][newv]) continue;
            if(kt2[newu][newv]==false)
            {
                kt2[newu][newv]=true;
                d1[newu][newv]=d1[u][v]+1;
                q1.push({newu,newv});
            }
        }
    }
}
void bfs2()
{
    queue<pair<int,int> > q;
    kt2[dau.fi][dau.se]=true;
    q.push(dau);
    d2[dau.fi][dau.se]=0;
    while(!q.empty())
    {
        auto [i,j]=q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            auto [u,v]=make_pair(i+dx[k],j+dy[k]);
            if(u<=0||v<=0||u>n||v>m||kt[u][v]) continue;
            if(kt2[u][v]==false&&d2[i][j]+1<d1[u][v])
            {
                kt2[u][v]=true;
                d2[u][v]=d2[i][j]+1;
                q.push({u,v});
                truy[u][v]={i,j};
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
        d1[i][j]=2e9;
        d2[i][j]=2e9;
        cin>>x;
        if(x=='A') dau={i,j};
        else if(x=='#') kt[i][j]=true;
        else if(x=='M')
        {
            q1.push({i,j});
            d1[i][j]=0;
            kt2[i][j]=true;
        }
    }
    bfs1();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            kt2[i][j]=false;
    bfs2();
    for(int i=1;i<=n;i++)
    {
        if(d2[i][1]!=2e9) {step=d2[i][1];dau={i,1};break;}
        if(d2[i][m]!=2e9) {step=d2[i][m];dau={i,m};break;}
    }
    for(int i=1;i<=m;i++)
    {
        if(d2[1][i]!=2e9) {step=d2[1][i];dau={1,i};break;}
        if(d2[n][i]!=2e9) {step=d2[n][i];dau={n,i};break;}
    }
    if(step>=0)
    {
        int vt3=dau.fi,vt4=dau.se;
        cout<<"YES\n"<<step<<'\n';
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
    }
    else cout<<"NO";
    return 0;
}
