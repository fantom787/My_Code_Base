#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double r, x1, x2, y1, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    int ans = ceil(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / (2.00 * r));
    cout << ans << endl;

    return 0;
}