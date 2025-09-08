#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int mod=1000000007;
int n,m;
ll dp[1002][1<<12];
vector<int> v[1<<12];
void tao(int i,int cur,int nxt,int st)
{
    if(i==n)
    {
        v[st].push_back(nxt);
        return;
    }
    if(cur&(1<<i))
        tao(i+1,cur,nxt,st);
    else
    {
        if(i+1<n&&!(cur&(1<<(i+1))))
            tao(i+2,cur,nxt,st);
        tao(i+1,cur,nxt|(1<<i),st);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    dp[0][0]=1;
    for(int ma=0;ma<(1<<n);ma++)
        tao(0,ma,0,ma);
    for(int i=0;i<m;i++)
    {
        for(int ma=0;ma<(1<<n);ma++)
        {
            for(int ma2:v[ma]){
                dp[i+1][ma2]+=dp[i][ma];
                dp[i+1][ma2]%=mod;
            }
        }
    }
    cout<<dp[m][0];
    return 0;
}
