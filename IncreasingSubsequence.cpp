#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
int len=0;
vector<ll> arr;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(arr.size()==0)arr.push_back(a);
        else if(a>arr[arr.size()-1]){
            arr.push_back(a);
            len++;
        }
        else if(a<=arr[0])arr[0]=a;
        else if(a<arr[arr.size()-1]){
            int y=lower_bound(arr.begin(),arr.end(),a)-arr.begin();
            if(arr[y]==a){
                arr[y]=a;
            }
            else{
            int x=upper_bound(arr.begin(),arr.end(),a)-arr.begin();
            arr[x]=a;}
            }
    }
    cout<<len+1;
    return 0;
}
