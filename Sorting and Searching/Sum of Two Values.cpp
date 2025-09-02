#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> a[200002];
int n,x;
int tim(int l,int r,int cc)
{
    int kq=r+1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid].first>=cc)
        {
            kq=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
   for(int i=1;i<=n;i++){
    cin>>a[i].first;
    a[i].second=i;
   }
   sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        int vt=tim(i+1,n,x-a[i].first);
        if(a[vt].first+a[i].first==x) {cout<<a[i].second<<' '<<a[vt].second;return 0;}
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
