#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();
ll INF = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    while (m--)
    {
        ll c, x;
        cin >> c >> x;
        vector<ll> u(2 * x);
        for (int i = 0; i < 2 * x; i++)
            cin >> u[i];
        ll temp = A[c - 1];
        A[c - 1] = 0;
        for (int i = 0; i < u.size() - 1; i += 2)
        {
            A[u[i + 1] - 1] = (A[u[i + 1] - 1] + temp * u[i]) % INF;
        }
    }
    for (auto x : A)
        cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    // cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}
