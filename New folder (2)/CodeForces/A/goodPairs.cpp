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
    ll n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    vector<int> b = arr;
    sort(all(b));
    ll min = b[0];
    ll max = b[n - 1];
    ll i1 = 0;
    int i2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (min == arr[i])
        {
            i1 = i + 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (max == arr[i])
        {
            i2 = i + 1;
            break;
        }
    }
    cout << i1 << " " <<i2 << endl;
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