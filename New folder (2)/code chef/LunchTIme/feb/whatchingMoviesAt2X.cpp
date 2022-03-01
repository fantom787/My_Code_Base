#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void solve()
{
    int x, y;
    cin >> x >> y;
    x -= y;
    cout << (x + (y / 2)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    // cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}