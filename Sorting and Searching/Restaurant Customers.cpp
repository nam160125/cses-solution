#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],b[200002],n,dem,mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    int i=0,j=0;
    while(i<n&&j<n)
    {
        if(a[i]<b[j]) {
            dem++;
            i++;
        }
        else if(a[i]>b[j])
        {
            dem--;
            j++;
        }
        else {
            i++;
            j--;
        }
        mx=max(mx,dem);
    }
    cout<<mx;
    return 0;
}
