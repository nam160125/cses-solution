#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
int n,k,dem,bit[200002];
void update(int i,int gt)
{
    for(i;i<=n;i+=i&(-i))
        bit[i]+=gt;
}
int get(int i)
{
    int dem=0;
    for(i;i>0;i-=i&(-i))
        dem+=bit[i];
    return dem;
}
int finds(int k)
{
    int idx=0,step=1<<18;
    for(step;step>0;step>>=1)
    {
        int nxt=idx+step;
        if(nxt<=n&&bit[nxt]<k)
        {
            k-=bit[nxt];
            idx=nxt;
        }
    }
    return idx+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) update(i,1);
    for(int i=n;i>=1;i--)
    {
        dem=(dem+k)%i;
        int pos=finds(dem+1);
        cout<<pos<<' ';
        update(pos,-1);
    }
    return 0;
}
