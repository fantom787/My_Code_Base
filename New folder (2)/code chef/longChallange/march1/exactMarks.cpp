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
    int n, x;
    cin >> n >> x;
    int a = x / 3;
    int b = 0;
    int c = 0;
    int remaining = x % 3;
    if (remaining == 1)
    {
        a += 1;
        b = 2;
    }
    else if (remaining == 2)
    {
        a += 1;
        b = 1;
    }
    if (a + b > n)
    {
        cout << "NO" << endl;
        return;
    }
    c = n - a - b;
    cout << "YES" << endl;
    cout << a << " " << b << " " << c << endl;
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