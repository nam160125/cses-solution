#include <bits/stdc++.h>
#define ll long long
using namespace std;
queue<int> cc;
int n;
bool flag;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cc.push(i);
   }
   while(!cc.empty())
   {
       int q=cc.front();
       cc.pop();
       if(flag)
           cout<<q<<' ';
           else cc.push(q);
        flag=!flag;
   }
    return 0;
}
