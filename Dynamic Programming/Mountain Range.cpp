#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,dp[200002];
pair<int,int> p[200002];
set<int,greater<int> > s1;
set<int> s2;
vector<int> cock;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>p[i].fi;
            p[i].se=i;
        }
    sort(p+1,p+n+1,greater<pii>());
    for(int i=1;i<=n;i++)
    {
        int gt=p[i].fi,vt=p[i].se;
        if(p[i].fi!=p[i-1].fi)
        {
            for(int j:cock)
            {
                s1.insert(j);
                s2.insert(j);
            }
            cock.clear();
        }
        auto it1=s1.lower_bound(vt),it2=s2.lower_bound(vt);
        int l=(it1==s1.end()?0:*it1),r=(it2==s2.end()?0:*it2);
        dp[vt]=max(dp[l],dp[r])+1;
        cock.push_back(vt);
    }
    cout<<*max_element(dp+1,dp+n+1);
    return 0;
}
