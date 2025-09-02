#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll cc=a[n-1];
    ll cc2=0;
    for(int i=0;i<n-1;i++)
        cc2+=a[i];
    if(cc<=cc2) cout<<cc2+cc;
        else cout<<cc*2;
    return 0;
}
