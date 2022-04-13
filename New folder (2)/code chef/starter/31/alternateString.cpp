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
    string s;
    cin >> n >> s;
    int cnt0 = 0;
    int cnt1 = 0;
    for (auto it : s)
    {
        if (it == '0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
    }
    int ans = 1;
    if (cnt1 == cnt0)
    {
        ans = n;
    }
    else if (cnt1 > cnt0)
    {
        ans = 2 * cnt0 + 1;
    }
    else if (cnt0 > cnt1)
    {
        ans = 2 * cnt1 + 1;
    }
    cout << ans << endl;
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