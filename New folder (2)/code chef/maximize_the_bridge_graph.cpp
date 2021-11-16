// https://www.codechef.com/NOV21C/problems/MAXBRIDGE

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
    ll n, m;
    cin >> n >> m;
    for (ll i = 2; i <= n; i++)
    {
        if (m == 0)
            break;
        cout << i - 1 << " " << i << "\n";
        m -= 1;
    }
    ll low = 1, high = n, c = -1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll sum = (mid * (mid - 1)) / 2;
        if (sum == (m + mid - 1))
        {
            c = mid;
            break;
        }
        else if (sum < (m + mid - 1))
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (c == -1)
        c = low;
    for (ll i = 1; i <= c; i++)
    {
        for (ll j = i + 2; j <= c; j++)
        {
            if (m == 0)
                break;
            cout << i << " " << j << "\n";
            m--;

            if (m == 0)
                break;
        }
    }
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