#include <bits/stdc++.h>
#define ll long long
using namespace std;
multiset<int> cc;
set<pair<int,int> > c;
int n,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>x>>n;
    c.insert({0,x});
    cc.insert(x);
    for(int i=0,y;i<n;i++)
    {
        cin>>y;
        auto it=c.upper_bound({y,0});
        it--;
        int l=it->first;
        int r=it->second;
        c.erase(it);
        cc.erase(cc.find(r-l));
        c.insert({l,y});
        c.insert({y,r});
        cc.insert(y-l);
        cc.insert(r-y);
        cout<<(*cc.rbegin())<<' ';
    }
    return 0;
}
