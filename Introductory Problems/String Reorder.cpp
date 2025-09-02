#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
string st;
int c[26];
char an[1000002];
bool ck(int cc)
{
    int tong=0,mx=0;
    for(int i=0;i<26;i++)
    {
        tong+=c[i];
        mx=max(mx,c[i]);
    }
    return (mx<=(tong+1)/2)&&(c[cc]<=tong/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>st;
    for(int i=0;i<st.size();i++)
        c[st[i]-'A']++;
    int luu=-1;
    for(int i=0;i<st.size();i++)
    {
        bool ok=0;
        for(int j=0;j<26&&!ok;j++)
        {
            if(c[j]>0&&j!=luu)
            {
                c[j]--;
                if(ck(j))
                {
                    ok=1;
                    an[i]=(char)(j+'A');
                    luu=j;
                }
                else c[j]++;
            }
        }
        if(!ok)
        {
            cout<<-1;return 0;
        }
    }
    for(int i=0;i<st.size();i++)
        cout<<an[i];
    return 0;
}
