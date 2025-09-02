#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],n;
ll tb,mn;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   cin>>n;
   for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int vt=a[n/2];
    for(int i=0;i<n;i++)
        mn+=abs(a[i]-vt);
    cout<<mn;
    return 0;
}
