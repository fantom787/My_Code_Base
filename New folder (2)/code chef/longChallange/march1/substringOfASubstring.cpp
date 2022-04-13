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
    string s;
    cin >> s;
    int n = sz(s);
    int i = 1;
    int j = 1;
    char first = s[0];
    char last = s[n - 1];
    int ans = 0;
    while (j < n - 1)
    {
        if (s[j] == first || s[j] == last)
        {
            j++;
            i = j;
        }
        else
        {
            j++;
        }
        ans = max(ans, (j - i));
    }
    if (!ans)
    {
        ans = -1;
    }
    cout << ans << endl;
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