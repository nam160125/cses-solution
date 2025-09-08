#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200002],b[200002],mx,vt,nt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        vt=lower_bound(b,b+nt,a[i])-b;
        if(vt==nt)
        {
            b[nt]=a[i];
            nt++;
        }
        else
        b[vt]=a[i];
        mx=max(mx,nt);
    }
    cout<<mx;
    return 0;
}
