#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,d[2][300002],x;
bool kt[300002];
vector<int> v[300002];
void bfs(int in,int s)
{
    queue<int> q;
    fill(d[in]+1,d[in]+n+1,0);
    fill(kt+1,kt+n+1,false);
    d[in][s]=0;
    kt[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j:v[u])
        {
            if(kt[j]==false)
            {
                kt[j]=true;
                d[in][j]=d[in][u]+1;
                q.push(j);
                if(d[in][x]<d[in][j]) x=j;
            }

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(0,1);
    bfs(0,x);
    bfs(1,x);
    for(int i=1;i<=n;i++)
       cout<<max(d[0][i],d[1][i])<<' ';
    return 0;
}
