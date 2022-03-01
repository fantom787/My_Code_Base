#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<bool> a(100005, false), b(100005, false);
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x; j < y + 1; j++)
        {
            a[j] = true;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x; j < y + 1; j++)
        {
            b[j] = true;
        }
    }
    int ans = 0;
    for (int i = l; i < r + 1; i++)
    {
        for (int j = 0; j < 1000 + 1; j++)
        {
            if (b[j] && a[j + i])
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}