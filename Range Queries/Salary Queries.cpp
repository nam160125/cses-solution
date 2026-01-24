#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
struct cc
{
    char truy;
    int u,v;
};
cc que[200002];
int n,q,m,a[200002],bit[400002];
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
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>que[i].truy>>que[i].u>>que[i].v;
        if(que[i].truy=='!') v.push_back(que[i].v);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    m=v.size();
    for(int i=1;i<=n;i++)
    {
        int vt=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        update(vt,1);
    }
    for(int i=1;i<=q;i++)
    {
        auto [ch,l,r]=que[i];
        if(ch=='!')
        {
            int vt=lower_bound(v.begin(),v.end(),a[l])-v.begin()+1;
            update(vt,-1);
            a[l]=r;
            vt=lower_bound(v.begin(),v.end(),a[l])-v.begin()+1;
            update(vt,1);
        }
        else
        {
            int vt=lower_bound(v.begin(),v.end(),l)-v.begin()+1;
            int vp=upper_bound(v.begin(),v.end(),r)-v.begin();
            cout<<get(vp)-get(vt-1)<<'\n';
        }
    }
    return 0;
}
