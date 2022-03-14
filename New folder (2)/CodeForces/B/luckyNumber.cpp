#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

bool cnt(ll n)
{
    ll cnt4 = 0;
    ll cnt7 = 0;
    while (n)
    {
        ll lst = n % 10;
        n /= 10;
        if (lst != 4 && lst != 7)
        {
            return false;
        }
        else if (lst == 4)
        {
            cnt4++;
        }
        else
        {
            cnt7++;
        }
    }
    return cnt4 == cnt7;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll ans = 0;
    ll cnt4 = 0;
    ll cnt7 = 0;
    bool f1 = true;
    while (f1)
    {
        if (cnt(n))
        {
            ans = n;
            f1 = false;
        }
        n++;
    }
    cout << ans << endl;
    return 0;
}
/*

9999
444777

99999
444777


*/