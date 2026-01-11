#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int n,m,k;
ll a[1002][1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fill(a[i]+1,a[i]+n+1,1000000000000000000);
    for(int i=1;i<=n;i++)
        a[i][i]=0;
    for(int i=1,x,y,z;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=a[y][x]=min((ll)z,min(a[x][y],a[y][x]));
    }
    for(int op=1;op<=n;op++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>a[i][op]+a[op][j]){
                a[i][j]=a[i][op]+a[op][j];
            }
        }
    for(int i=1,x,y,z;i<=k;i++)
    {
        cin>>x>>y;
        cout<<(a[x][y]==1000000000000000000?-1:a[x][y])<<'\n';
    }
    return 0;
}
