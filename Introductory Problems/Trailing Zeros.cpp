#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,kq;
ll dem(int k)
{
    ll dem=0,d=5;
   while(k/d>0)
   {
       dem+=k/d;
       d*=5;
   }
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
   cout<<dem(n);
    return 0;
}
