#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,a[102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        a[i][j] = i^j;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
