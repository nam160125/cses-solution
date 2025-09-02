#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[30],a[30],n;
ll mx=LLONG_MAX;
bool ck;
void write()
{
    ll dem=0;
    for(int i=1;i<=n;i++)
        if(x[i]==1) dem+=a[i];
    else dem-=a[i];
    mx=min(mx,abs(dem));
}
void Try(int i)
{
   if(i>n)
   {
       write();
       return;
   }
   for(int j=1;j<3;j++)
   {
       x[i]=j;
       Try(i+1);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   // freopen("BTKHOANVI.INP","r",stdin);
   // freopen("BTKHOANVI.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    Try(1);
    cout<<mx;
    return 0;
}
