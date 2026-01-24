#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n,m,a[200002],bit[200002];
void update(int i,int gt)
{
    for(i;i<=n;i+=i&(-i))
        bit[i]+=gt;
}
int finds(int k)
{
    int pos=0,buoc=1<<17;
    while(buoc)
    {
        int nxt=pos+buoc;
        if(nxt<=n&&bit[nxt]<k)
        {
            k-=bit[nxt];
            pos=nxt;
        }
        buoc>>=1;
    }
    return pos+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,1);
    }
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        int vt=finds(x);
        cout<<a[vt]<<' ';
        update(vt,-1);
    }
    return 0;
}
