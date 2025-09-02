#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll t,x,y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>y>>x;
        if(y<x)
        {
            if(x%2==0) cout<<(x-1)*(x-1)+y<<'\n';
            else cout<<x*x-y+1<<'\n';
        }
        else
        {
            if(y%2==0) cout<<y*y-x+1<<'\n';
            else cout<<(y-1)*(y-1)+x<<'\n';
        }
    }
    return 0;
}
