#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n;
char a[3002][3002];
bool kt[3002][3002],kt2[3002][3002];
string an;
vector<pii> cur;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
    an+=a[1][1];
    cur.push_back({1,1});
    for(int step=1;step<=2*(n-1);step++)
    {
        vector<pii> nxt;
        for(auto [i,j]:cur)
        {
            if(i+1<=n&&kt[i+1][j]==false)
            {
                nxt.push_back({i+1,j});
                kt[i+1][j]=true;
            }
            if(j+1<=n&&kt[i][j+1]==false)
            {
                nxt.push_back({i,j+1});
                kt[i][j+1]=true;
            }
        }
        char mn='Z'+1;
        for(auto [i,j]:nxt)
            mn=min(mn,a[i][j]);
        vector<pii> tiep;
        for(auto [i,j]:nxt)
            if(mn==a[i][j]&&kt2[i][j]==false)
        {
            tiep.push_back({i,j});
            kt2[i][j]=true;
        }
        an.push_back(mn);
        cur.swap(tiep);
    }
    cout<<an;
    return 0;
}
