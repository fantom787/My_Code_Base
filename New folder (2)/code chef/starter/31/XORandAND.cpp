#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7
#define ppc __builtin_popcount
#define ppcll _builtin_popcount
#define sz(x) (int)x.size()

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    sort(all(arr));
    ll large = arr.back();
    ll ans = 0;
    ll x = 1;
    while (x << 1 < large)
    {
        int cnt = 0;
        for (auto it : arr)
        {
            if (it >= x && it < (x << 1))
            {
                cnt++;
            }
        }
        if (cnt > 1)
        {
            ans += (cnt * (cnt - 1) / 2);
        }
        x <<= 1;
    }
    ll cnt = 0;
    for (auto it : arr)
    {
        if (it == x)
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        ans += ((cnt) * (cnt - 1) / 2);
    }
    cout << ans+1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}