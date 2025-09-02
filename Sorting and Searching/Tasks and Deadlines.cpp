#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> p[200002];
int n;
ll dem,kq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        dem+=p[i].first;
        kq+=p[i].second-dem;
    }
    cout<<kq;
    return 0;
}
