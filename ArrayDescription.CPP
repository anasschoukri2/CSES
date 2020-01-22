#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
vector<int>v;
int n,m;
ll dp[100007][105];
ll cnt(int i,int last){
    if(i>=n)return 1;
    if(v[i]){
        if(abs(v[i]-last)>1)return -oo;
        return cnt(i+1,v[i]);
    }
    if(dp[i][last]+1)return dp[i][last];
    ll ans=0;
    int a=cnt(i+1,last),b=cnt(i+1,min(last+1,m)),c=cnt(i+1,max(last-1,0));
    if(a>=0)ans+=(a%MOD);
    if(b>=0&&last+1<=m)ans+=(b%MOD);
    if(c>=0&&last-1>=1)ans+=(c%MOD);
    return dp[i][last]=ans%MOD;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    ms(dp,-1);
    ll ans=0;
    if(v[0]){
    cout<<max(cnt(1,v[0]),(ll)0)%MOD;
    return  0;
    }
    else
    for(int i=1;i<=m;i++){
        if(cnt(1,i)>=0)ans+=(cnt(1,i)%MOD);
    }
    cout<<max((ll)0,ans)%MOD;
    return 0;
}
