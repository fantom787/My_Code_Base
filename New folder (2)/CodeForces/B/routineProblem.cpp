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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    double t = (1.00 * (double)y / x) * a;
    int p, q;
    if (t > b)
    {
        p = x * b * b;
        q = a * b * y;
    }
    else
    {
        p = a * a * y;
        q = a * b * x;
    }
    double k = __gcd(p, q);
    p /= k;
    q /= k;
    p = q - p;
    cout << p << "/" << q << endl;
    return 0;
}
/*

 area = (x/y)*b*b/a*b
   x*b*b/a*b*y;

    a*(y/x)*a/a*b
    a*a*y
    a*b*x



*/