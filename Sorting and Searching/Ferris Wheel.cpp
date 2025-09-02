#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],n,x,dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int i=0,j=n-1;
    while(i<=j)
    {
        if(i==j) {dem++;break;}
        if(a[i]+a[j]<=x) {
            dem++;
            i++;
            j--;
        }
        else {
            dem++;
            j--;
        }
    }
    cout<<dem;
    return 0;
}
