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
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    while (!(x % d))
    {
        cnt++;
        x /= d;
    }
    if (cnt == 1)
    {
        cout << "NO" << endl;
        return;
    }
    else if (cnt == 2)
    {
        
    }
    else if (cnt == 3)
    {
    }
    else
    {
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