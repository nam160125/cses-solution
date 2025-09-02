#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int>a[26];
int d;
string st,kq;
bool ck;
bool ck2(string s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j]) return 0;
        i++;j--;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   cin>>st;
   if(ck2(st)) {cout<<st;return 0;}
   for(int i=0;i<st.size();i++)
    a[st[i]-'A'].first++;
  for(int i=0;i<26;i++)
    {
       if(a[i].first%2!=0) d++;
       a[i].second=i;
    }
    if(d>1) {
        cout<<"NO SOLUTION";
        return 0;
    }
     sort(a,a+26);
    for(int i=25;i>=0;i--){
        string cc="";
        for(int j=1+(a[i].first%2!=0);j<=a[i].first;j++){
            cc+=(char)(a[i].second+'A');
        }
        kq.insert(kq.size()/2,cc);
    }
    for(int i=25;i>=0;i--)
        if(a[i].first%2!=0)
    {
        string cc="";
        cc+=(char)(a[i].second+'A');
        kq.insert(kq.size()/2,cc);
    }
    cout<<kq;
    return 0;
}
