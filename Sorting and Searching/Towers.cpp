#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],b[200002],n,ntn;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>a[i];
   for(int i=0;i<n;i++)
   {
       int vt=upper_bound(b,b+ntn,a[i])-b;
       if(vt==ntn)
       {
           b[ntn]=a[i];
           ntn++;
       }
       else b[vt]=a[i];
   }
   cout<<ntn;
    return 0;
}
