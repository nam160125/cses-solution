#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    int u,v,gt;
};
bool cmp(cc a,cc b)
{
    if(a.v==b.v) return a.u<b.u;
    return a.v<b.v;
}
int n,m;
ll bit[400002];
cc p[200002];
vector<int> v;
void update(int i,ll gt)
{
    while(i<=m)
    {
        bit[i]=max(bit[i],gt);
        i+=i&(-i);
    }
}
ll get(int i)
{
    ll mx=0;
    for(i;i>0;i-=i&(-i))
        mx=max(mx,bit[i]);
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].u>>p[i].v>>p[i].gt;
        v.push_back(p[i].v);
        v.push_back(p[i].u);
    }
    sort(p+1,p+n+1,cmp);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    m=v.size();
    for(int i=1;i<=n;i++)
    {
        int vt=lower_bound(v.begin(),v.end(),p[i].u)-v.begin();
        int vp=lower_bound(v.begin(),v.end(),p[i].v)-v.begin()+1;
        update(vp,get(vt)+p[i].gt);
    }
    cout<<get(m);
    return 0;
}
