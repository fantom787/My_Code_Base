#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

ll digiSum(int n)
{
    ll ans = 0;
    while (n)
    {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll val = sqrt(n);
    for (int i = val; i >= max(val - 100, (ll)0); i--)
    {
        if (i * (i + digiSum(i)) == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}