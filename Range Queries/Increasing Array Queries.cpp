#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll,ll>
using namespace std;
int n,q,l,r,a[200002],ri[200002],up[19][200002];
ll pre[200002],sum[19][200002];
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
        ri[i]=(st.empty()?n+1:st.top());
        st.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        int j=ri[i]-1;
        ll cak=1ll*(j-i)*a[i]-(pre[j]-pre[i]);
        sum[0][i]=cak;
        up[0][i]=j+1;
    }
    for(int k=1;k<19;k++)
        for(int i=1;i<=n;i++)
    {
        up[k][i]=(up[k-1][i]==n+1?n+1:up[k-1][up[k-1][i]]);
        sum[k][i]=sum[k-1][i]+sum[k-1][up[k-1][i]];
    }
    while(q--)
    {
        cin>>l>>r;
        ll dem=0;
        for(int k=18;k>=0;k--)
            if(up[k][l]<=r)
        {
            dem+=sum[k][l];
            l=up[k][l];
        }
        dem+=1ll*(r-l+1)*a[l]-(pre[r]-pre[l-1]);
        cout<<dem<<'\n';
    }
    return 0;
}
