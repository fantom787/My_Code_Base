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
        cout << n << " " << lst << " ";
        if (lst != 4 && lst != 7)
        {
            cout << "lst: " << lst << endl;
            return false;
        }
        else if (lst == 4)
        {
            cnt4++;
        }
        else if (lst == 7)
        {
            cnt7++;
        }
    }
    cout << "cnt4: " << cnt4 << "cnt7: " << cnt7 << endl;
    return cnt4 == cnt7;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << cnt(47);
    return 0;
}