#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,m,indeg[100002],outdeg[100002];
stack<int> st;
vector<int> v[100002],an;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        indeg[y]++;
        outdeg[x]++;
        v[x].push_back(y);
    }
    bool ok=true;
    if(n!=1)
    {
        if(outdeg[1]!=indeg[1]+1) ok=false;
        if(outdeg[n]+1!=indeg[n]) ok=false;
        for(int i=2;i<n;i++)
            if(indeg[i]!=outdeg[i])
            {
                ok=false;break;
            }
    }
    if(!ok)
    {
        cout<<"IMPOSSIBLE";return 0;
    }
    st.push(1);
    while(!st.empty())
    {
        int u=st.top();
        if(v[u].size())
        {
            int vv=v[u].back();
            v[u].pop_back();
            st.push(vv);
        }
        else
        {
            an.push_back(u);
            st.pop();
        }
    }
    if(an.size()!=m+1||an.back()!=1||an.front()!=n) cout<<"IMPOSSIBLE";
    else
    {
        for(int i=an.size()-1;i>=0;i--) cout<<an[i]<<' ';
    }
    return 0;
}
