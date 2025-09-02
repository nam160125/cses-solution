#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll dem=0,mx=LLONG_MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0,x;i<n;i++)
    {
        cin>>x;
        dem+=x;
        mx=max(mx,dem);
        if(dem<0) dem=0;
    }
    cout<<mx;
    return 0;
}
