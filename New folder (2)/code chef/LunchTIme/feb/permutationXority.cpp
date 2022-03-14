#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    if (n % 2)
    {
        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = n; i > 3; i--)
        {
            cout << i << " ";
        }
        cout << 1 << " " << 3 << " " << 2;
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