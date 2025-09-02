#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,a,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(a+b>n||((a==0)^(b==0)))
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
                cout<<i<<' ';
            cout<<'\n';
            for(int i=a+1;i<=a+b;i++)
                cout<<i<<' ';
            for(int i=1;i<=a;i++)
                cout<<i<<' ';
            for(int i=a+b+1;i<=n;i++)
                cout<<i<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
