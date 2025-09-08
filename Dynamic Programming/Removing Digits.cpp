#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt;
short mx(int n)
{
    short k=0;
    while(n)
    {
        k=max(k,(short)(n%10));
        n/=10;
    }
    return k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n)
    {
        n-=mx(n);
        cnt++;
    }
    cout<<cnt;
    return 0;
}
