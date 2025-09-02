#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
   ll x=1;
   for(int i=1;i<=n;i++){
   if(a[i]>x) {break;}
   x+=a[i];
   }
   cout<<x;
    return 0;
}
