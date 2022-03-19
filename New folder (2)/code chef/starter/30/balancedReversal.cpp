#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    sort(all(a));
    cout << a << endl;
    return ;
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