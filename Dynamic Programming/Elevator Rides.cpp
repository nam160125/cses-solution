#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,x,a[25];
pair<int,int> dp[1<<21];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0]={1,0};
    for(int mask=1;mask<(1<<n);mask++)
    {
        dp[mask]={21,0};
        for(int i=0;i<n;i++)
            if(mask&(1<<i))
            {
                auto [sl,t]=dp[mask^(1<<i)];
                if(t+a[i]>x)
                {
                    sl++;
                    t=min(a[i],t);
                }
                else t+=a[i];
                dp[mask]=min(dp[mask],{sl,t});
            }
    }
    cout<<dp[(1<<n)-1].fi;
    return 0;
}
