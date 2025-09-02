#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200002],n,t,mx;
ll kq;
bool ck(ll cc)
{
    ll dem=0;
    for(int i=0;i<n;i++){
        dem+=(cc/a[i]);
   if(dem>=t) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   cin>>n>>t;
   for(int i=0;i<n;i++){
    cin>>a[i];
    mx=max(mx,a[i]);
   }
   ll l=1,r=mx*t;
   while(l<=r)
   {
       ll mid=(l+r)/2;
       if(ck(mid))
       {
           kq=mid;
           r=mid-1;
       }
       else l=mid+1;
   }
   cout<<kq;
    return 0;
}
