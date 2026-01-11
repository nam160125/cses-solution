#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n;
bool kt[300002];
vector<int> an;
void dfs(int i)
{
    for(int j=0;j<2;j++)
    {
        int idx=i*2+j;
        if(kt[idx]==false)
        {
            kt[idx]=true;
            dfs(idx&((1<<(n-1))-1));
            an.push_back(j);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<"01";
        return 0;
    }
    dfs(0);
    for(int i=1;i<n;i++) cout<<0;
    for(int i=an.size()-1;i>=0;i--) cout<<an[i];
    return 0;
}
