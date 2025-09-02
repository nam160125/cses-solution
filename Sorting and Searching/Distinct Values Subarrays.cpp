#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,a[200002];
ll dem;
unordered_map<int,int> c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int i=1,j=1;
    while(i<=n&&j<=n)
    {
        if(c[a[j]]==0)
        {
            dem+=j-i+1;
            c[a[j]]++;
            j++;
        }
        else
        {
            c[a[i]]--;
            i++;
        }
    }
    cout<<dem;
    return 0;
}
