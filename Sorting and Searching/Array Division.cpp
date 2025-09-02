#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],n,k;
ll res,tong;
bool ck(ll kq)
{
    ll dem=0;
    int cc=1;
    for(int i=0;i<n;i++)
    {
        dem+=a[i];
        if(dem>kq)
        {
            dem=a[i];
            cc++;
        }
    }
    return (cc<=k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tong+=a[i];
    }
    ll l=*max_element(a,a+n),r=tong;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(ck(mid))
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<res;
    return 0;
}
