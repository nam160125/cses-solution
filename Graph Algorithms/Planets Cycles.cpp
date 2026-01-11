#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int n,step,buoc[200002],a[200002];
bool kt[200002];
queue<int> q;
void dfs(int i)
{
    q.push(i);
    if(kt[i])
    {
        step+=buoc[i];
        return;
    }
    kt[i]=true;
    step++;
    dfs(a[i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("hangbi.inp","r")){
        freopen("hangbi.inp","r",stdin);
        freopen("hangbi.out","w",stdout);
    }
    cin>>n;
    for(int i=1,x;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(kt[i]==false)
        {
            step=0;
            dfs(i);
            int dec=1;
            while(!q.empty())
            {
                if(q.front()==q.back()) dec=0;
                buoc[q.front()]=step;
                step-=dec;
                q.pop();
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<buoc[i]<<' ';
    return 0;
}
