#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    int n, x;
    cin >> n >> x;
    bool flag = false;
    for (int i = 0; i < n && !flag; i++)
    {
        if (x % (n - i) == 0 && x / (n - i) < i + 2)
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
/*
Div 2 : C
Check linearly for each n-i and possible correct remainder.

AC
It's like, suppose you have window of size (n-k) then (n-k) should divide x and the quotient can only be 1 to k+1
*/