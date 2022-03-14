#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double ans = a / b;

    double k = ((b - a) / b) * ((d - c) / d);
    ans /= (1 - k);

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}