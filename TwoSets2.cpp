#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
ll n;
ll dp[504][63376];
ll x = 0;
ll cnt(int i, ll sum1)
{
    if (sum1 > x)
        return 0;
    if (i == n + 1) {
        return (sum1 == x - sum1);
    }
    if (dp[i][sum1] + 1)
        return (dp[i][sum1] % MOD);
    return dp[i][sum1] = ((cnt(i + 1, sum1 + i) % MOD) + (cnt(i + 1, sum1) % MOD));
}
int main()
{
    cin >> n;
    for (int i = 0; i < 502; i++) {
        for (int j = 0; j < 63376; j++) {
            dp[i][j] = -1;
        }
    }
    x = n * (n + 1);
    x /= 2;
    ll k = cnt(1, 0) / 2;
    cout << k;
    return 0;
}
