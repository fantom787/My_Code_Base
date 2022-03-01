#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string ans = "";
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (abs(sa + x - sb) <= 500)
        {
            ans += "A";
            sa += x;
        }
        else
        {
            ans += "G";
            sb += y;
        }
    }
    if (abs(sa - sb) > 500)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}