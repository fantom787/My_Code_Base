#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }
    ll ans = 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            ans += (a[i] - a[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}