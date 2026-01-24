#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll,ll>
using namespace std;
int n,q,l,r,a[100002],up[18][100002];
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
        up[0][i]=(st.empty()?n+1:st.top());
        st.push(i);
    }
    for(int k=1;k<18;k++)
        for(int i=1;i<=n;i++)
        up[k][i]=(up[k-1][i]==n+1?n+1:up[k-1][up[k-1][i]]);
    while(q--)
    {
        cin>>l>>r;
        int dem=0;
        for(int k=17;k>=0;k--)
            if(up[k][l]<=r)
        {
            dem+=(1<<k);
            l=up[k][l];
        }
        cout<<dem+1<<'\n';
    }
    return 0;
}
