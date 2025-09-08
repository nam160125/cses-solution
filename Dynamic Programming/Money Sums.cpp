#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[102];
ll f[100002],sum;
bool kt[100002];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=sum;j>=a[i];j--){
        f[j]+=f[j-a[i]];
        if(!kt[j]&&f[j]>0){
            v.push_back(j);
            kt[j]=1;
        }
        }
    cout<<v.size()<<'\n';
    sort(v.begin(),v.end());
    for(int i:v)
        cout<<i<<' ';
    return 0;
}
