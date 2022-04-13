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
    ll ans = 0;
    ll p = 1;
    ll cnt = 0;
    while (p << 1 <= n)
    {
        p <<= 1;
        cnt++;
        ans += (pow(2, cnt - 1) - 1);
    }
    ans += (n - p);
    cout << ans << endl;
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