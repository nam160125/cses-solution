#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,int> c;
ll f[200002],k,dem;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
   for(int i=1,x;i<=n;i++)
   {
       cin>>x;
       f[i]=f[i-1]+x;
   }
   for(int i=1;i<=n;i++)
   {
       c[f[i-1]+k]++;
       dem+=c[f[i]];
   }
   cout<<dem;
    return 0;
}
