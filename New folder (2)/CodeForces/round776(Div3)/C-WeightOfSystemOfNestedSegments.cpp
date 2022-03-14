#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(x) x.begin(), x.end()

class in
{
public:
    ll x;
    ll i;
    ll w;
    in(ll x, ll i, ll w)
    {
        this->x = x;
        this->i = i;
        this->w = w;
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<in> pts;
    for (int i = 0; i < m; i++)
    {
        ll x, w;
        cin >> x >> w;
        pts.emplace_back(x, i, w);
    }
    sort(all(pts), [](auto a, auto b)
         { return a.w < b.w; });
    ll w = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < 2 * n; i++)
    {
        w += pts[i].w;
        v.push_back({pts[i].x, pts[i].i + 1});
    }
    cout << w << endl;
    sort(all(v));
    for (int i = 0,j=2*n-1; i<j; i++,j--)
    {
        cout << v[i].second << " " << v[j].second << endl;
    }
    cout << endl;
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
