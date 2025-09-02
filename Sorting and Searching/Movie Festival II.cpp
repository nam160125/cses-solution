#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
pair<int,int> a[200002];
int n,k,cnt,dem;
multiset<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1);
    for(int i=1;i<=k;i++)
        s.insert(a[i].se);
    for(int i=k+1;i<=n;i++)
    {
        auto mn=s.begin();
        auto mx=s.rbegin();
        if(a[i].fi>=*mn)
        {
            dem++;
            s.erase(mn);
            s.insert(a[i].se);
        }
        else if(a[i].se<*mx)
        {
            s.erase(s.find(*mx));
            s.insert(a[i].se);
        }
    }
    cout<<dem+(int)s.size();
    return 0;
}
