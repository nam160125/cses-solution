#include <bits/stdc++.h>
#define ll long long
#define GLORY_GLORY_MAN_UNITED return 0
using namespace std;
void Move(int n,int x,int y,int z)
{
    if(n==0) return;
    Move(n-1,x,z,y);
    cout<<x<<' '<<y<<'\n';
    Move(n-1,z,y,x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cout<<(ll)pow(2,n)-1<<'\n';
    Move(n,1,3,2);
    GLORY_GLORY_MAN_UNITED;
}
