#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define oo 100000000
#define ll long long int
#define MOD 1000000007
using namespace std;
int n, m;
pair<ll, ll> dp[5007][5007][2];
vector<int> s;
vector<ll> v;
int p[100007];
pair<ll, ll> cnt(int i, int j, bool t)
{
    if (i == j)
        return { (!t) * v[i], (t)*v[i] };
    if (dp[i][j][t].first)
        return dp[i][j][t];
    pair<ll, ll> ans = { cnt(i + 1, j, !t).first + (!t) * v[i], (t)*v[i] + cnt(i + 1, j, !t).second };
    pair<ll, ll> ans2 = { cnt(i, j - 1, !t).first + (!t) * v[j], (t)*v[j] + cnt(i, j - 1, !t).second };
    if (!t) {
        if (ans.first > ans2.first)
            return dp[i][j][t] = ans;
        else if (ans.first < ans2.first)
            return dp[i][j][t] = ans2;
    }
    else {
        if (ans.second > ans2.second)
            return dp[i][j][t] = ans;
        else if (ans.second < ans2.second)
            return dp[i][j][t] = ans2;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    cout << cnt(0, v.size() - 1, 0).first;
    return 0;
}
