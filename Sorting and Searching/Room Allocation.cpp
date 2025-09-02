#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    int u,v,idx;
};
bool cmp(cc a,cc b)
{
    return a.u<b.u;
}
cc a[200002];
int n,an[200002],cnt;
priority_queue<pii,vector<pii>,greater<pii> > pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].u>>a[i].v;
        a[i].idx=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(pq.empty()||pq.top().fi>=a[i].u){
            cnt++;
            pq.push({a[i].v,cnt});
            an[a[i].idx]=cnt;
        }
        else
        {
            int nroom=pq.top().se;
            pq.pop();
            pq.push({a[i].v,nroom});
            an[a[i].idx]=nroom;
        }
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
        cout<<an[i]<<' ';
    return 0;
}
