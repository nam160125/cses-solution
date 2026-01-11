#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,m,cnt,scc,low[200004],num[200004],comp[200004];
bool kt[200004];
char ch1,ch2;
vector<int> v[200004];
stack<int> st;
void dfs(int i)
{
    st.push(i);
    num[i]=low[i]=++cnt;
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
    if(low[i]==num[i])
    {
        scc++;
        int cc;
        do
        {
            cc=st.top();
            st.pop();
            comp[cc]=scc;
            kt[cc]=true;
        }
        while(cc!=i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=n;i++)
    {
        cin>>ch1>>x>>ch2>>y;
        int idx1=x*2+(ch1=='-'),idx2=y*2+(ch2=='-');
        v[idx1^1].push_back(idx2);
        v[idx2^1].push_back(idx1);
    }
    for(int i=1;i<=2*m+1;i++)
        if(kt[i]==false) dfs(i);
    for(int i=1;i<=m;i++)
    if(comp[2*i]==comp[2*i+1]) {cout<<"IMPOSSIBLE";return 0;}
    for(int i=1;i<=m;i++)
        cout<<(comp[2*i]>comp[2*i+1]?'-':'+')<<' ';
    return 0;
}
