#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> a[200002];
int f[200002],n,mx;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a,a+n,cmp);
    int cc=0,mx=0;
    for(int i=0;i<n;i++)
        if(a[i].first>=cc)
    {
        cc=a[i].second;
        mx++;
    }
    cout<<mx;
    return 0;
}
