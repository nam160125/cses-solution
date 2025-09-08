#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
string a,b;
ll f[20][10][2][2];
ll dp(string s,int pos,int oldi,bool ck1,bool ck2)
{
    if(pos==0) return 1;
    if(ck1&&f[pos][oldi][ck1][ck2]!=-1) return f[pos][oldi][ck1][ck2];
    ll res=0;
    int maxdi=(ck1?9:s[s.size()-pos]-48);
    for(int di=0;di<=maxdi;di++)
    {
        int nxtck1=ck1||(di<s[s.size()-pos]-48);
        if(ck2)
        {
            if(di!=oldi)
                res+=dp(s,pos-1,di,nxtck1,1);
        }
        else if(di>0)
            res+=dp(s,pos-1,di,nxtck1,1);
        else res+=dp(s,pos-1,di,nxtck1,0);
    }
    if(ck1)
        f[pos][oldi][ck1][ck2]=res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b;
    memset(f,-1,sizeof(f));
    if(a=="0") cout<<dp(b,b.size(),0,0,0);
    else {
        int i=a.size()-1;
        while(i>=0)
        {
            if(a[i]>'0') {a[i]--;break;}
            a[i]='9';
            i--;
        }
        while(a.size()>1&&a[0]=='0') a.erase(0,1);
        ll an1=dp(a,a.size(),0,0,0);
        ll an2=dp(b,b.size(),0,0,0);
        cout<<an2-an1;
    }
    return 0;
}
