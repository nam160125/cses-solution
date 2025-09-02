#include <bits/stdc++.h>
#define ll long long
using namespace std;
int vt[200002],n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int dem=1;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        vt[x]=i;
    }
    for(int i=1;i<n;i++)
        if(vt[i+1]<vt[i]) dem++;
    cout<<dem;
    return 0;
}
