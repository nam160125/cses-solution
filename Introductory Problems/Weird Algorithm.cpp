#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n!=1)
    {
        cout<<n<<' ';
        if(n%2==0) n/=2;
        else n=n*3+1;
    }
    cout<<1;
    return 0;
}
