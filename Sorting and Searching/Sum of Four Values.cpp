#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> a[1002];
int n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n-3;i++)
        for(int j=i+1;j<n-2;j++)
    {
        int l=j+1,r=n-1;
        int cc=x-a[i].first-a[j].first;
        while(l<r)
        {
            if(a[l].first+a[r].first==cc)
            {
                cout<<a[i].second<<' '<<a[j].second<<' '<<a[l].second<<' '<<a[r].second;
                return 0;
            }
            else if(a[l].first+a[r].first<cc)
                l++;
                else r--;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
