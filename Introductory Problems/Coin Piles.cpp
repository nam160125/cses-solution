#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t,a,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if((a+b)%3==0&&(a+b)/3<=a&&(a+b)/3<=b) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
