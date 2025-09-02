#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[200005],dem,n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll k=1;
    const ll cc=(1000000000/n+1)*n;
   for(int i=1;i<=n;i++)
   {
       cin>>x;
       x+=cc;
       x%=n;
       f[i]=(f[i-1]+x)%n;
   }
    sort(f+1,f+n+1);
    f[n+1]=1000000000000000000;
    for(int i=1;i<=n;i++){
        if(f[i]==f[i+1]) k++;
        else if(k>1)
        {
            dem+=k*(k-1)/2;
            k=1;
        }
        if(f[i]==0) dem++;
    }
   cout<<dem;
    return 0;
}
