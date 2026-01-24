#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct cc
{
    int truy,l,r;
};
cc que[200002];
int n,q,a[200002],nxt[400002],st[800002];
vector<int> v;
set<int> s[400002];
void update(int i,int l,int r,int vt,int gt)
{
    if(l==r)
    {
        st[i]=gt;
        return;
    }
    int mid=l+r>>1;
    if(vt<=mid) update(i<<1,l,mid,vt,gt);
    else update(i<<1|1,mid+1,r,vt,gt);
    st[i]=min(st[i<<1],st[i<<1|1]);
}
int get(int i,int l,int r,int a,int b)
{
    if(r<a||l>b) return 2e9;
    if(l>=a&&r<=b) return st[i];
    int mid=l+r>>1;
    return min(get(i<<1,l,mid,a,b),get(i<<1|1,mid+1,r,a,b));
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
    for(int i=1,truy,l,r;i<=q;i++)
    {
        cin>>truy>>l>>r;
        que[i]={truy,l,r};
        if(truy==1) v.push_back(r);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        s[a[i]].insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        auto it=s[a[i]].find(i);
        if(next(it)!=s[a[i]].end())
            nxt[i]=*next(it);
        else nxt[i]=n+1;
        update(1,1,n,i,nxt[i]);
    }
    for(int i=1;i<=q;i++)
    {
        auto [truy,l,r]=que[i];
        if(truy==2)
        {
            int cak=get(1,1,n,l,r);
            if(cak<=r) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else
        {
            int vt=lower_bound(v.begin(),v.end(),r)-v.begin()+1,old=a[l];
            if(vt==old) continue;
            auto it=s[old].find(l);
            int prv=(it==s[old].begin()?-1:*prev(it));
            int nx=(next(it)==s[old].end()?n+1:*next(it));
            if(prv!=-1)
            {
                nxt[prv]=nx;
                update(1,1,n,prv,nxt[prv]);
            }
            s[old].erase(it);
            it=s[vt].lower_bound(l);
            prv=(it==s[vt].begin()?-1:*prev(it));
            nx=(it==s[vt].end()?n+1:*it);
            if(prv!=-1)
            {
                nxt[prv]=l;
                update(1,1,n,prv,nxt[prv]);
            }
            nxt[l]=nx;
            update(1,1,n,l,nxt[l]);
            s[vt].insert(l);
            a[l]=vt;
        }
    }
    return 0;
}
