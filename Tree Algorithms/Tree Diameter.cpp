#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,kt[200002],x,kq;
vector<int> v[200002];
void dfs(int i,int cnt,int &mx)
{
    kt[i]=true;
    cnt++;
    for(int j:v[i])
    {
        if(kt[j]==false)
        {
            if(cnt>=mx)
            {
                mx=cnt;
                x=j;
            }
            dfs(j,cnt,mx);
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
    dfs(1,0,kq);
    fill(kt,kt+n+1,false);
    dfs(x,0,kq);
    cout<<kq;
    return 0;
}
