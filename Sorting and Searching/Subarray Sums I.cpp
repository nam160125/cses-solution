#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[200002];
int n,x,dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1,x;i<=n;i++)
        {
      cin>>x;
      f[i]=f[i-1]+x;
        }
  for(int i=1;i<=n;i++)
  {
      int vt=lower_bound(f+1,f+n+1,x+f[i-1])-f;
      if(f[vt]-f[i-1]==x) dem++;
  }
  cout<<dem;
    return 0;

}
