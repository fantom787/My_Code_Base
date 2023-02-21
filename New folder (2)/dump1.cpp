#include <bits/stdc++.h>
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define pb push_back
#define ll long long
const ll mod = 1e9 + 7;
const ll INF = 2e18;
using namespace std;

int main()
{

    fastio();

    ll n, x, y;
    cin >> n >> x >> y;

    vector<vector<ll>> cost(n + 2, vector<ll>(n + 2));
    for (ll i = 0; i < n + 2; i++)
    {
        for (ll j = 0; j < n + 2; j++)
        {
            cin >> cost[i][j];
            // cout<<cost[i][j]<<' ';
        }
        // cout<<'\n';
    }

    // cout<<cost[1][0]<<endl;

    vector<vector<ll>> dp((1ll << (n + 2)), vector<ll>(n + 2, INF));
    vector<ll> fin((1ll << (n + 2)), INF);

    dp[1][0] = 0;
    // cost[0][0] = INF;

    for (ll i = 0; i < (1ll << (n + 1)); i++)
    {
        for (ll j = 1; j < n + 2; j++)
        {
            if ((i & (1ll << j)) == 0)
            {
                ll supmask = i | (1ll << j);
                // if (supmask == 3)cout<<"hi";
                for (ll k = 0; k < n + 1; k++)
                {
                    if (i & (1ll << k))
                    {
                        // if (supmask == (1ll << (n + 1)) + 1)cout<<k<<' '<<2 * y * cost[k][j] + dp[i][k]<<endl;

                        dp[supmask][j] = min(dp[supmask][j], 2 * y * cost[k][j] + dp[i][k]);
                        fin[supmask] = min(fin[supmask], x + dp[supmask][j]);
                    }
                }
            }
        }
    }

    // cout<<dp[(1ll << (n + 1)) + 1][n + 1]<<endl;
    // cout<<fin[(1ll << (n + 1)) + 1];

    for (ll i = 0; i < (1ll << (n + 2)); i++)
    {
        ll sum = 1;
        for (ll j = 1; j < n; j++)
        {
            sum += (1ll << j);
            ll rem = i - sum;
            fin[i] = min(fin[i], fin[sum] + fin[rem]);
        }
    }

    cout << fin[(1ll << (n + 2)) - 1];

    return 0;
}