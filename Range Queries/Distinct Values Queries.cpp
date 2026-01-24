#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
struct cc
{
    int x,y,idx;
};
cc que[200002];
int n,q,an[200002],a[200002],c[200002],blc,dist;
vector<int> v;
bool cmp(cc a,cc b)
{
    if(a.x/blc!=b.x/blc) return a.x<b.x;
    return a.y<b.y;
}
void add(int i)
{
    c[a[i]]++;
    if(c[a[i]]==1)  dist++;
}
void rem(int i)
{
    c[a[i]]--;
    if(c[a[i]]==0) dist--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    blc=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    for(int i=1;i<=q;i++){
        cin>>que[i].x>>que[i].y;
        que[i].idx=i;
    }
    sort(que+1,que+q+1,cmp);
    int cl=1,cr=0;
    for(int i=1;i<=q;i++)
    {
        auto [l,r,cock]=que[i];
        while(cr<r) add(++cr);
        while(cr>r) rem(cr--);
        while(cl>l) add(--cl);
        while(cl<l) rem(cl++);
        an[cock]=dist;
    }
    for(int i=1;i<=q;i++)
        cout<<an[i]<<'\n';
    return 0;
}
