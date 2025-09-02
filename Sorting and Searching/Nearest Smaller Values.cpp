#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> p[200002],a[200002];
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
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   //freopen("PTHUONG.inp","r",stdin);
   //freopen("PTHUONG.out","w",stdout);
    int n,ntn=0;
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>p[i].first;
            p[i].second=i+1;
        }
    for(int i=0;i<n;i++)
    {
        int vt=bound(0,ntn-1,p[i].first)-1;
        if(vt==-1) {cout<<0<<' ';}
        else
            cout<<a[vt].second<<' ';
         while(a[ntn-1].first>=p[i].first&&ntn>0)
         {
             a[ntn-1].first=0;
             a[ntn-1].second=0;
             ntn--;
         }
         a[ntn].first=p[i].first;
         a[ntn].second=p[i].second;
         ntn++;
    }
    return 0;
}
