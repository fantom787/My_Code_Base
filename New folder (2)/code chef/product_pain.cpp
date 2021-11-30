// https://www.codechef.com/SNCKPE21/problems/PRDTPAIN
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll maxx = a[i], minn = a[i];
        set<ll> s;
        for (ll j = i; j < n; j++)
        {
            s.insert(a[j]);
            maxx = max(maxx, a[j]);
            minn = min(minn, a[j]);
            if (j - i < 2)
                continue;
            ll val = 0;
            auto pos = s.lower_bound((maxx + minn) / 2);
            if (pos != s.end())
            {
                val = max(val, (maxx - (*pos)) * ((*pos) - minn));
            }
            if (pos != s.begin())
            {
                pos--;
                val = max(val, (maxx - (*pos)) * ((*pos) - minn));
            }
            ans += val;
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