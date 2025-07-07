#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,a[200002];
ll cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        if(a[i]<a[i-1])
        {
            cnt+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    cout<<cnt;
    return 0;
}
