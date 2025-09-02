#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n;
bool kt[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0,x;i<n-1;i++)
    {
        cin>>x;
        kt[x]=true;
    }
    for(int i=1;i<=n;i++)
    if(kt[i]==false) {cout<<i;break;}
    return 0;
}
