#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
vector<int>v;
int n,m;
int dp[502][505];
int cnt(int x1,int y1,int x2,int y2){
    if(x2-x1==y2-y1)return 0;
    int ans=oo;
    if(dp[x2-x1][y2-y1]+1)return dp[x2-x1][y2-y1];
    if(dp[y2-y1][x2-x1]+1)return dp[y2-y1][x2-x1];
    for(int i=x1+1;i<x2;i++){
        ans=min(ans,cnt(x1,y1,i,y2)+cnt(i,y1,x2,y2)+1);
    }
    for(int i=y1+1;i<y2;i++){
        ans=min(ans,cnt(x1,i,x2,y2)+cnt(x1,y1,x2,i)+1);
    }
    return dp[y2-y1][x2-x1]=dp[x2-x1][y2-y1]=ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    ms(dp,-1);
    cout<<cnt(0,0,a,b);
    return 0;
}
