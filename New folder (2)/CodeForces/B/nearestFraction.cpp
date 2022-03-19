#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define INF 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x, y, n;
    cin >> x >> y >> n;
    int a = 0;
    int b = 0;
    double diff = INF;
    for (int i = 1; i <= n; i++)
    {
        int num = ((double)x * i) / y;
        double temp = abs(((1.0 * x) / (1.0 * y)) - ((num * 1.0) / (i * 1.0)));
        if (temp < diff)
        {
            diff = temp;
            a = num;
            b = i;
        }
        temp = abs(((1.0 * x) / (1.0 * y)) - (((num + 1) * 1.0) / (i * 1.0)));
        if (temp < diff)
        {
            diff = temp;
            a = num + 1;
            b = i;
        }
    }

    cout << a << "/" << b << endl;
    return 0;
}