#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll p, d;
    cin >> p >> d;
    ll temp = p;
    ll pow10 = 1;
    ll ans = p;
    ll val = p;
    while (temp)
    {
        pow10 *= 10;
        int sub = 0;
        if (temp % 10 != 9)
        {
            sub = 1;
        }
        temp /= 10;
        temp -= sub;
        val = temp * pow10 + pow10 - 1;
        if (p - val <= d)
        {
            ans = val;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}