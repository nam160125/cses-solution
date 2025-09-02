#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
string st;
int cnt,Max;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>st;
    for(int i=0;i<st.size();i++)
    {
        if(st[i]==st[i+1]) cnt++;
        else
        {
            Max=max(Max,cnt+1);
            cnt=0;
        }
    }
    cout<<Max;
    return 0;
}
