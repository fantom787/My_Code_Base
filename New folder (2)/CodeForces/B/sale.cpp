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
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    sort(price);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (price[i] < 0)
        {
            ans += price[i];
        }
    }
    ans = abs(ans);
    cout << ans << endl;

    return 0;
}