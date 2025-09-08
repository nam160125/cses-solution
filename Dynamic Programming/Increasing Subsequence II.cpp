#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int mod=1000000007;
int n,a[200002];
ll bit[200002];
vector<int> v;
void update(int i,ll gt)
{
    for(i;i<=n;i+=i&(-i))
        bit[i]=(bit[i]+gt)%mod;
}
ll get(int i)
{
    ll dem=0;
    for(i;i>0;i-=i&(-i))
        dem=(dem+bit[i])%mod;
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
    {
        ll cak=1;
        int vt=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        cak=(cak+get(vt-1))%mod;
        update(vt,cak);
    }
    cout<<get(n);
    return 0;
}
