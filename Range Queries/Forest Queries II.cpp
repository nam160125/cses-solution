#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,q,truy,x,y,u,v,bit[1002][1002];
char a[1002][1002];
void update(int i,int j,int del)
{
    for(int u=i;u<=n;u+=u&(-u))
        for(int v=j;v<=n;v+=v&(-v))
        bit[u][v]+=del;
}
int get(int i,int j)
{
    int dem=0;
    for(int u=i;u>0;u-=u&(-u))
        for(int v=j;v>0;v-=v&(-v))
        dem+=bit[u][v];
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        update(i,j,(a[i][j]=='*'));
    }
    while(q--)
    {
        cin>>truy>>x>>y;
        if(truy==1){
            if(a[x][y]=='*')
            {
                update(x,y,-1);
                a[x][y]='.';
            }
            else
            {
                update(x,y,1);
                a[x][y]='*';
            }
        }
        else
        {
            cin>>u>>v;
            cout<<get(u,v)-get(x-1,v)-get(u,y-1)+get(x-1,y-1)<<'\n';
        }
    }
    return 0;
}
