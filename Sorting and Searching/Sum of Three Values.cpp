#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> a[200002];
int n,x;
int bound(int l,int r,int cc)
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
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++)
            {
                int vt=bound(j+1,n-1,x-a[i].first-a[j].first);
                if((ll)a[vt].first+a[i].first+a[j].first==x) {
                    cout<<a[i].second<<' '<<a[j].second<<' '<<a[vt].second;
                    return 0;
                }
            }
    cout<<"IMPOSSIBLE";
    return 0;
}
