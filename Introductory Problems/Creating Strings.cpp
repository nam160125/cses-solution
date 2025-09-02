#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<string> c;
set<string>::iterator i;
string st;
void cc()
{
    do
    {
        c.insert(st);
    }
    while(next_permutation(st.begin(),st.end()));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   // freopen("BTKHOANVI.INP","r",stdin);
   // freopen("BTKHOANVI.OUT","w",stdout);
    cin>>st;
    sort(st.begin(),st.end());
    cc();
    cout<<c.size()<<'\n';
   for(i=c.begin();i!=c.end();i++)
    cout<<*i<<'\n';
    return 0;
}
