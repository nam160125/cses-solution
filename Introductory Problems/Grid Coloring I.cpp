#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("GRAPH.inp","r"))
    {
        freopen("GRAPH.inp","r",stdin);
        freopen("GRAPH.out","w",stdout);
    }
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            if(x=='A'||x=='B')
            {
                if((i+j)&1) cout<<'D';
                else cout<<'C';
            }
            else
            {
                if((i+j)&1) cout<<'B';
                else cout<<'A';
            }
        }
        cout<<'\n';
    }
    return 0;
}
