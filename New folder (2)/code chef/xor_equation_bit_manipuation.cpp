// https://www.codechef.com/NOV21C/problems/XOREQN

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
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll ans = 0;
    for (ll j = 0; j <= 61; j++)
    {
        ll one = 0;
        for (ll i = 0; i < n; i++)
            if ((1ll << j) & arr[i])
                one++;
        if (one % 2 == 0)
            continue;
        if (j == 61)
        {
            ans = -1;
            break;
        }
        ans += (1ll << j);
        for (ll i = 0; i < n; i++)
            arr[i] += (1ll << j);
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