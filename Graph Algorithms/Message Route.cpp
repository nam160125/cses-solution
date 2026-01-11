#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
bool kt[100002];
vector<int> v[100002],kq;
int n,m,s,t,d[100002],truy[100002];
void bfs(int i)
{
    queue<int> q;
    kt[i]=true;
    q.push(i);
    while(!q.empty())
    {
        int cc=q.front();
        q.pop();
        for(int j:v[cc])
        {
            if(kt[j]==false){
                if(d[j]>d[cc]+1)
                {
                    d[j]=d[cc]+1;
                    truy[j]=cc;
                }
                 kt[j]=true;
                q.push(j);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    s=1,t=n;
    for(int i=0,x,y;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    fill(d,d+n+1,1000000000);
    truy[s]=s;
    d[s]=0;
    bfs(s);
    if(kt[t]==false) {cout<<"IMPOSSIBLE";return 0;}
    while(t!=truy[t])
    {
        kq.push_back(t);
        t=truy[t];
    }
    kq.push_back(t);
    cout<<kq.size()<<'\n';
    for(int i=kq.size()-1;i>=0;i--)
        cout<<kq[i]<<' ';
    return 0;
}
