#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    int u,v,id;
};
bool cmp(cc a,cc b)
{
    if(a.u==b.u) return a.v>b.v;
    return a.u<b.u;
}
int n,m,an[200002],an2[200002],bit[400002];
cc p[200002];
vector<int> v;
void update(int i,int gt)
{
    for(i;i<=m;i+=i&(-i))
        bit[i]+=gt;
}
int get(int i)
{
    int dem=0;
    for(i;i>0;i-=i&(-i))
        dem+=bit[i];
    return dem;
}
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].u>>p[i].v;
        v.push_back(p[i].u);
        v.push_back(p[i].v);
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    m=v.size();
    for(int i=1;i<=n;i++)
    {
        int vt=lower_bound(v.begin(),v.end(),p[i].v)-v.begin()+1;
        an2[p[i].id]=get(m)-get(vt-1);
        update(vt,1);
    }
    fill(bit+1,bit+m+1,0);
    for(int i=n;i>=1;i--)
    {
        int vt=lower_bound(v.begin(),v.end(),p[i].v)-v.begin()+1;
        an[p[i].id]=get(vt);
        update(vt,1);
    }
    for(int i=1;i<=n;i++)
        cout<<an[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++)
        cout<<an2[i]<<' ';
    return 0;
}
