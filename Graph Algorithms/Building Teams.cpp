#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,an[100002];
vector<int> v[100002];
bool kt[100002],ok=1;
void bfs(int s)
{
    queue<pair<int,int> > q;
    q.push({s,1});
    kt[s]=true;
    an[s]=1;
    while(!q.empty())
    {
        auto [u,du]=q.front();
        q.pop();
        for(int j:v[u])
        {
            if(kt[j]==false)
            {
                kt[j]=true;
                an[j]=(du==1?2:1);
                q.push({j,an[j]});
            }
            else
                if(an[j]==an[u]) {ok=0;return;}
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
        if(kt[i]==false)
        bfs(i);
    if(ok) for(int i=1;i<=n;i++) cout<<an[i]<<' ';
    else cout<<"IMPOSSIBLE";
    return 0;
}
