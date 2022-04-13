#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7
#define ppc __builtin_popcount
#define ppcll _builtin_popcount
#define sz(x) (int)x.size()

void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
        }
    }
    if (sz(odd) <= 1 || (sz(odd) == n && (n & 1)))
    {
        cout << -1 << endl;
        return;
    }
    if (sz(odd) & 1)
    {
        cout << odd[0] << " ";
        odd.erase(odd.begin());
    }
    for (auto it : even)
    {
        cout << it << " ";
    }
    for (auto it : odd)
    {
        cout << it << " ";
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