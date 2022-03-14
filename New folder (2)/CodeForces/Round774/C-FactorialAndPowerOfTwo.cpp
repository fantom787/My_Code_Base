#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    vector<ll> fact(16, 1);
    for (int i = 1; i < 16; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    ll n;
    cin >> n;
    ll ans = INT_MAX;
    for (ll mask = 0; mask < 1 << 15; mask++)
    {
        ll sum = 0;
        ll ppc = __builtin_popcountll(mask);
        for (int i = 0; i < 14; i++)
        {
            if (mask & (1 << i))
                sum += fact[i + 1];
        }
        if (sum <= n)
        {
            ll val = __builtin_popcountll(n - sum) + ppc;
            ans = min(ans, val);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}