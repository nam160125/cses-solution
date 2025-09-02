#include <bits/stdc++.h>
#define ll long long
using namespace std;
multiset<int> c;
multiset<int>::iterator vt;
int n,m,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        c.insert(x);
    }
    for(int i=0;i<m;i++)
    {
        cin>>x;
        vt=c.upper_bound(x);
        if(vt!=c.begin())
        vt--;
        else {cout<<-1<<'\n';continue;}
        cout<<(*vt)<<'\n';
        c.erase(vt);
    }
    return 0;
}
