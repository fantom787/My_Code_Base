#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> sb(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll y = __builtin_popcountll(x);
        sb[i] = {y, i};
    }
    vector<ll> ans;
    sort(sb);
    ll i = 0;
    ll j = 0;
    while (j < n)
    {
        while (j - i + 1 >= 2 && sb[i++].first == sb[j].first)
        {
            i--;
            ans.push_back(sb[i++].second);
            ans.push_back(sb[i++].second);
        }
        j++;
    }
    if (ans.size() < 4)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans[0] + 1 << " " << ans[2] + 1 << " " << ans[1] + 1 << " " << ans[3] + 1 << endl;
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
/*
Div 2-B
Print maximum between count of zeros and length of array -count of zeros
*/