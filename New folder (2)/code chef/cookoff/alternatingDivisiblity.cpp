#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    ll n;
    cin >> n;
    vector<ll> num(n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            num[i] = i + 1;
        }
        else
        {
            num[i] = 2 * num[i - 1];
        }
    }
    for (auto it : num)
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
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}