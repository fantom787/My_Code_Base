#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    
    ll n, q, x, y;
    cin >> n >> q;
    string s, p;
    cin >> s >> p;
    ll v[n], od[n], ev[n];
    for (ll i = 0; i < n; i++)
    {
        if (p[i] >= s[i])
            v[i] = (p[i] - s[i]);
        else
            v[i] = 26 - (s[i] - p[i]);
    }

    od[0] = 0;
    ev[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        if (i % 2)
            od[i] = od[i - 1] + v[i], ev[i] = ev[i - 1];
        else
            od[i] = od[i - 1], ev[i] = ev[i - 1] + v[i];
    }

    ll s1, s2;
    for (ll i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        s1 = od[y], s2 = ev[y];
        if (x > 0)
            s1 -= od[x - 1], s2 -= ev[x - 1];

        if (abs(s1 - s2) % 26 == 0)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
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
