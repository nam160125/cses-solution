#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,nt,Time,dem,an[100002],low[100002],num[100002];
bool kt[100002];
vector<int> v[100002],cak[100002];
stack<int> st;
void dfs(int i)
{
    low[i]=num[i]=++Time;
    st.push(i);
    for(int j:v[i])
    {
        if(kt[j]==false){
            if(num[j])
            {
                low[i]=min(low[i],num[j]);
            }
            else
            {
                dfs(j);
                low[i]=min(low[i],low[j]);
            }
        }
    }
    if(low[i]==num[i])
    {
        int cc;
        dem++;
        do
        {
            cc=st.top();
            st.pop();
            cak[dem].push_back(cc);
            kt[cc]=true;
        }
        while(cc!=i);
    }
}
void dfs2(int i,int start)
{
    kt[i]=true;
    an[nt++]=i;
    for(int j:v[i])
        if(kt[j]==false)
        {
            dfs2(j,start);
            nt--;
        }
    else if(j==start)
    {
        an[nt++]=an[0];
        cout<<nt<<'\n';
        for(int i=0;i<nt;i++)
            cout<<an[i]<<' ';
        exit(0);
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
    }
    for(int i=1;i<=n;i++)
        if(!kt[i]) dfs(i);
    fill(kt+1,kt+n+1,false);
    for(int i=1;i<=dem;i++){
        if(cak[i].size()>1){
            dfs2(cak[i][0],cak[i][0]);
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
