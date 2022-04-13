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
    int n, m;
    cin >> n >> m;
    vector<string> rec(n);
    for (auto &it : rec)
    {
        cin >> it;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (rec[i][j] + rec[i + 1][j] + rec[i][j + 1] + rec[i + 1][j + 1] - 4 * '0' == 3)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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