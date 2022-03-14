#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = abs(x);
    }
    ll sum = 0;
    ll maxi = INT_MIN;
    ll mini = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        if (i & 1)
        {
            maxi = max(maxi, a[i]);
            sum -= a[i];
        }
        else
        {
            mini = min(mini, a[i]);
            sum += a[i];
        }
    }
    if (mini < maxi)
    {
        sum += 2 * maxi;
        sum -= 2 * mini;
    }
    cout << sum << endl;
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
