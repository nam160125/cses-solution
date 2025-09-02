#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
string st;
int dem,way[4],p[50];
bool kt[9][9];
void Try(int i=0,int j=1,int k=1)
{
    if(j==7&&k==1&&i<48) return;
    if(i==48)
    {
        if(j==7&&k==1) dem++;
        return;
    }
    if(kt[j][k]) return;
    for(int idx=0;idx<4;idx++)
    {
        int newj=j+dx[idx],newk=k+dy[idx];
            way[idx]=kt[newj][newk];
    }
    if(way[0]&&way[2]&&!way[1]&&!way[3]) return;
    if(!way[0]&&!way[2]&&way[1]&&way[3]) return;
    kt[j][k]=true;
    if(p[i]<4)
    {
        int newj=j+dx[p[i]],newk=k+dy[p[i]];
        if(!kt[newj][newk]) Try(i+1,newj,newk);
    }
    else
        for(int idx=0;idx<4;idx++)
        {
            int newj=j+dx[idx],newk=k+dy[idx];
            if(!kt[newj][newk])
            Try(i+1,newj,newk);
        }
    kt[j][k]=false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>st;
    for(int i=0;i<st.size();i++)
    {
        if(st[i]=='U') p[i]=0;
        else if(st[i]=='R') p[i]=1;
       else if(st[i]=='D') p[i]=2;
        else if(st[i]=='L') p[i]=3;
        else p[i]=4;
    }
    for(int i=0;i<=8;i++)
        kt[0][i]=kt[8][i]=kt[i][0]=kt[i][8]=true;
    Try();
    cout<<dem;
    return 0;
}
