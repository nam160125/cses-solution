#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
struct cc
{
    int x,l,r,del,id;
};
bool cmp(cc a,cc b)
{
    return a.x<b.x;
}
int n,q,bit[200002],an[200002];
pair<int,int> a[200002];
vector<cc> sk;
void update(int i,int gt)
{
    for(i;i<=n;i+=i&(-i))
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
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    for(int i=1,l,r,c,d;i<=q;i++)
    {
        cin>>l>>r>>c>>d;
        sk.push_back({c-1,l,r,-1,i});
        sk.push_back({d,l,r,1,i});
    }
    sort(sk.begin(),sk.end(),cmp);
    int i=1;
    for(auto [x,l,r,del,id]:sk)
    {
        while(i<=n&&a[i].fi<=x)
        {
            update(a[i].se,1);
            i++;
        }
        an[id]+=(get(r)-get(l-1))*del;
    }
    for(int i=1;i<=q;i++) cout<<an[i]<<'\n';
    return 0;
}
