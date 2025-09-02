#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
int a[200002],n,mx;
map<int,int> c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        if(n==1) {cout<<1;return 0;}
    int i=0,j=1;
    c[a[0]]++;
    while(i<n&&j<n)
    {
        if(c[a[j]]<1)
        {
            c[a[j]]++;
            j++;
        }
        else
        {
            c[a[i]]--;
            i++;
        }
        mx=max(mx,j-i);
    }
    cout<<mx;
    return 0;
}
