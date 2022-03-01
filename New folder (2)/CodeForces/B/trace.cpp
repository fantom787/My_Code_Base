#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int
#define pi 3.1415926535;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> radius(n);
    for (int i = 0; i < n; i++)
    {
        cin >> radius[i];
    }
    sort(radius.begin(), radius.end());
    int ans = 0;

    int x = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int rad = radius[i];
        ans += (x * rad * rad);
        x *= -1;
    }

    double realAns = double(ans) * pi;
    cout << fixed << setprecision(10) << realAns << endl;
    return 0;
}