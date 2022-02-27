#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll f1, f2;
    cin >> f1 >> f2;
    ll n;
    cin >> n;
    n = n % 6;
    ll ans;
    // Giving TLE
    if (!n)
    {
        cout << (f1 - f2 + mod + mod + mod + mod) % mod << endl;
    }
    else if (n == 1)
    {
        cout << (f1 + mod + mod) % mod << endl;
    }
    else if (n == 2)
    {
        cout << (f2 + mod + mod) % mod << endl;
    }
    else
    {
        ll prev1 = f2, prev2 = f1;
        ll curr;
        for (int i = 0; i < n - 2; i++)
        {
            curr = ((prev1 - prev2) + mod + mod) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        cout << (curr + mod) % mod << endl;
    }

    return 0;
}