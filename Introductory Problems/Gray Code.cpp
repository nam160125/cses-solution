#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        vector<int> s(n);
        int gg=i^(i>>1);
        for(int j=n-1;j>=0;j--)
        {
            if(gg&1) s[j]=1;
            else s[j]=0;
            gg>>=1;
        }
        for(int i:s) cout<<i;
        cout<<'\n';
    }
    return 0;
}
