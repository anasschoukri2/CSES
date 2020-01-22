#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
int n,m;
int dp[104][100004];
vector<int>s;
vector<int>v;
int p[100007];
void cnt(int i,int sum){
    if(i==v.size()){if(!p[sum]){p[sum]=true;s.push_back(sum);}return ;}
    if(dp[i][sum])return ;
    dp[i][sum]=true;
    cnt(i+1,sum);
    cnt(i+1,sum+v[i]);
    return ;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cnt(0,0);
    sort(s.begin(),s.end());
    cout<<s.size()-1<<endl;
    for(int i=0;i<s.size();i++){
        if(s[i]!=0){
            cout<<s[i]<<" ";
        }
    }
    return 0;
}
