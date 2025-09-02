#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cc;
set<int> c;
set<int>::iterator i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int kk=n;
    cc=n*(n+1)/2;
    if(cc%2!=0) cout<<"NO\n";
    else {
        cout<<"YES\n";
        cc/=2;
        while(cc>0)
        {
            if(cc>=n)
            {
                c.insert(n);
                cc-=n;
                n--;
            }
            else {
                c.insert(cc);
                cc=0;
            }
        }
        cout<<c.size()<<'\n';
        for(i=c.begin();i!=c.end();i++)
            cout<<(*i)<<' ';
        cout<<'\n'<<kk-c.size()<<'\n';
        for(int i=1;i<=kk;i++)
        if(c.find(i)==c.end()) cout<<i<<' ';
    }
    return 0;
}
