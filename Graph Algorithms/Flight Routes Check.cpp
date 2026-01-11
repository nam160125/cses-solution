#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,low[100002],num[100002],t[100002],dem,cnt;
int leekangin[100002],leekangout[100002],v1,v2;
bool kt[100002];
vector<int> v[100002];
stack<int> st;
void dfs(int i)
{
    num[i]=low[i]=++cnt;
    st.push(i);
    for(int j:v[i])
    {
        if(kt[j]==false)
        {
            if(num[j]==0)
            {
                dfs(j);
                low[i]=min(low[i],low[j]);
            }
            else low[i]=min(low[i],num[j]);
        }
    }
    int cc;
    if(low[i]>=num[i])
    {
        dem++;
        do
        {
            cc=st.top();
            st.pop();
            t[cc]=dem;
            kt[cc]=true;
        }
        while(cc!=i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("DUATHLON.INP","r")){
    freopen("DUATHLON.INP","r",stdin);
    freopen("DUATHLON.OUT","w",stdout);
    }
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
        v[i].push_back(i);
    for(int i=1;i<=n;i++)
        if(kt[i]==false)
        dfs(i);
    for(int i=1;i<=n;i++)
        for(int j:v[i])
        if(t[i]!=t[j])
    {
        leekangin[t[j]]++;
        leekangout[t[i]]++;
    }
    for(int i=1;i<=dem;i++)
        if(leekangin[i]==0) {v1=i;break;}
    for(int i=1;i<=dem;i++)
        if(leekangout[i]==0&&i!=v1) {v2=i;break;}
    if(dem==1) {cout<<"YES";}
    else
    {
        cout<<"NO\n";
        for(int i=1;i<=n;i++)
        if(t[i]==v1) {v1=i;break;}
        for(int i=1;i<=n;i++)
        if(t[i]==v2) {v2=i;break;}
        cout<<v2<<' '<<v1;
    }
    return 0;
}
