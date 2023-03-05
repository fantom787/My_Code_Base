// team outings
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll aa[18][18][1ll << 18], cnt = 0;
ll d[20][20];
ll n, x, y;
ll dp[20][20], dp1[20];
ll solve(ll x1, ll y1, ll mask)
{
    if (aa[x1][y1][mask] != -1)
        return aa[x1][y1][mask];
    if (mask == 0)
        return 2 * d[x1][n + 1] * y;
    ll st = y1 - cnt + 1, ans1 = 1e18;
    for (int i = 0; i < cnt; i++)
    {
        if (mask & (1ll << i))
        {
            ll ans2 = 2 * d[x1][st + i] * y + solve(st + i, y1, mask ^ (1ll << i));
            ans1 = min(ans1, ans2);
        }
    }
    return aa[x1][y1][mask] = ans1;
}
int main()
{
    ll i, j;
    cin >> n >> x >> y;
    memset(aa, -1, sizeof(aa));
    for (int i = 0; i < n + 2; i++)
    {
        dp1[i] = 1e18;
        for (int j = 0; j < n + 2; j++)
        {
            dp[i][j] = 1e18;
            cin >> d[i][j];
        }
    }
    dp1[0] = 0;
    for (i = 0; i < n + 2; i++)
    {
        cnt = 1;
        dp[i][i] = x + (d[0][i] + d[i][n + 1]) * 2 * y;
        for (j = i + 1; j <= n + 1; j++)
        {
            cnt++;
            ll tot = (1ll << cnt), ans = 1e18;
            for (int k = i; k <= j; k++)
                ans = min(ans, x + 2 * d[0][k] * y + solve(k, j, tot - (1ll << (k - i)) - 1));
            dp[i][j] = ans;
        }

    }
    for (i = 1; i < n + 1; i++)
    {
        dp1[i] = dp[0][i];
        for (int j = 0; j < i; j++)
        {
            dp1[i] = min(dp1[i], dp[0][j] + dp[j + 1][i]);
        }
    }
    cout << dp1[n] << endl;


}
/*
dp[j]=dp[i]+min_val(i+1,j);
ans=dp[n];
dp[j] is min cost to get/move first j elements
for all i 0 to j-1
min_val(i+1,j) will get calculated using bitmask dp
like to take i+1 to j in a single cab there can be many ways..so the min of all that can be calculated using a bitmask dp 


*/