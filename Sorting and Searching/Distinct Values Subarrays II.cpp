#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200002],n,k;
unordered_map<int,int> c;
ll dem;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i=0,j=0;
    c[a[0]]++;
    while(i<n&&j<n)
    {
        dem+=j-i+1;
        c[a[j+1]]++;
        j++;

        while(c.size()>k)
        {
            c[a[i]]--;
            if(c[a[i]]==0) c.erase(a[i]);
            i++;
        }
    }
    cout<<dem;
    return 0;
}
