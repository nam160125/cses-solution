#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,tam;
int dp[5002][5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    s1=" "+s1;
    s2=" "+s2;
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int j=1;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
    }
    cout<<dp[n][m];
    return 0;
}
