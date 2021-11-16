#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
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
}