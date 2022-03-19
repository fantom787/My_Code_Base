#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }
    sort(all(a));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            k -= a[i];
            ans++;
        }
        else
        {
            if ((a[i] + 1) / 2 <= k)
            {
                ans++;
                break;
            }
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