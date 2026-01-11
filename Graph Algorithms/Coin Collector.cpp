#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,m,scc,tim,a[100002],tp[100002];
int num[100002],low[100002],deg[100002];
bool kt[100002];
ll dp[100002],aa[100002];
stack<int> st;
vector<int> v[100002],g[100002],topo;
set<pii> ck;
void dfs(int i)
{
    low[i]=num[i]=++tim;
    st.push(i);
    for(int j:v[i])
    {
        if(kt[j]==false)
        {
            if(num[j])
                low[i]=min(low[i],num[j]);
            else
            {
                dfs(j);
                low[i]=min(low[i],low[j]);
            }
        }
    }
    if(low[i]==num[i])
    {
        ++scc;
        int cc;
        do
        {
            cc=st.top();
            st.pop();
            aa[scc]+=a[cc];
            tp[cc]=scc;
            kt[cc]=true;
        }
        while(cc!=i);
    }
}
void tspo()
{
    queue<int> q;
    for(int i=1;i<=scc;i++)
        if(deg[i]==0) q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int j:g[u])
            if(--deg[j]==0) q.push(j);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("hangbi.inp","r")){
        freopen("hangbi.inp","r",stdin);
        freopen("hangbi.out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
        if(kt[i]==false) dfs(i);
    for(int i=1;i<=n;i++)
        for(int j:v[i])
        if(tp[i]!=tp[j]&&ck.count({tp[i],tp[j]})==0)
            {
                g[tp[i]].push_back(tp[j]);
                deg[tp[j]]++;
                ck.insert({tp[i],tp[j]});
            }
    tspo();
    for(int i:topo) dp[i]=aa[i];
    for(int i:topo)
        for(int j:g[i])
        dp[j]=max(dp[j],dp[i]+aa[j]);
    cout<<*max_element(dp+1,dp+scc+1);
    return 0;
}
