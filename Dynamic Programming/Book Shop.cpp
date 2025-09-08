#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,x,a[1000002];
pair<int,int> p[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>p[i].fi;
    for(int i=1;i<=n;i++)
        cin>>p[i].se;
    for(int i=1;i<=n;i++)
        for(int j=x;j>=p[i].fi;j--)
        a[j]=max(a[j],a[j-p[i].fi]+p[i].se);
    cout<<a[x];
    return 0;
}
