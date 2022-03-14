#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    ll l, r, a;
    cin >> l >> r >> a;
    ll ans = (r / a) + (r % a);
    if (r - 1 >= l)
    {
        ans = max(ans, ((r - 1) / a + (r - 1) % a));
    }
    ll x = r - r % a;
    if (x - 1 >= l)
    {
        ans = max(ans, ((x - 1) / a + (x - 1) % a));
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
