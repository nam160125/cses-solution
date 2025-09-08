#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x,a[102];
int f[10000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=x;i++)
       {
           f[i]=1000000000;
           for(int j=1;j<=n;j++)
           if(i>=a[j])
            f[i]=min(f[i],f[i-a[j]]+1);
        }
    cout<<(f[x]!=1000000000?f[x]:-1);
    return 0;
}
