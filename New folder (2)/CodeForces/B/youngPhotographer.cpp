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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, xo;
    cin >> n >> xo;
    vector<int> arr(1001);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = min(a, b); j <= max(a, b); j++)
        {
            arr[j + 1]++;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 1001; i++)
    {
        // cout << arr[i] << " ";
        if (arr[i] == n)
        {
            ans = min(ans, abs(xo - i + 1));
        }
    }
    if (ans == INT_MAX)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}