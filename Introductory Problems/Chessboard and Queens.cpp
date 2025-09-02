#include <bits/stdc++.h>
#define ll long long
#define GLORY_GLORY_MAN_UNITED return 0
using namespace std;
char a[10][10];
int x[11];
bool cot[11],cheo1[21],cheo2[21];
ll dem;
void Try(int i)
{
    if(i>8){
        dem++;
        return;
    }
    for(int j=1;j<=8;j++)
    {
        if(cot[j]==0&&cheo1[i+j]==0&&cheo2[i-j+8]==0&&a[i][j]!='*')
        {
            x[i]=j;
            cot[j]=cheo1[i+j]=cheo2[i-j+8]=1;
            Try(i+1);
              cot[j]=cheo1[i+j]=cheo2[i-j+8]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("btkbina2.inp","r",stdin);
//    freopen("btkbina2.out","w",stdout);
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        cin>>a[i][j];
    Try(1);
    cout<<dem;
    GLORY_GLORY_MAN_UNITED;
}
