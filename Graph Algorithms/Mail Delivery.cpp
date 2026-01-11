#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,m,in[100002],deg[100002];
vector<pii> v[100002];
vector<int> an;
bool kt[200002];
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        deg[x]++;deg[y]++;
        v[x].push_back({y,i});
        v[y].push_back({x,i});
    }
    for(int i=1;i<=n;i++)
    if(deg[i]%2!=0) {cout<<"IMPOSSIBLE";return 0;}
    st.push(1);
    while(!st.empty())
    {
        int u=st.top();
        while(in[u]<v[u].size()&&kt[v[u][in[u]].se]) ++in[u];
        if(in[u]==v[u].size())
        {
            an.push_back(u);
            st.pop();
        }
        else
        {
            auto pp=v[u][in[u]];
            kt[pp.se]=true;
            st.push(pp.fi);
            ++in[u];
        }
    }
    if((int)an.size()!=m+1) cout<<"IMPOSSIBLE";
    else
    for(int i:an) cout<<i<<' ';
    return 0;
}
