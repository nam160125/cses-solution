#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],b[200002],n,m,k,dem,vp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<n;i++)
    {
        int vt=lower_bound(b+vp,b+m,a[i]-k)-b;
        if(b[vt]<=a[i]+k&&vt<m) {dem++;vp=vt+1;}
    }
    cout<<dem;
    return 0;
}
