#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void solve()
{
    unordered_set<int> st = {6, 7, 13, 14, 20, 21, 27, 28};
    int n;
    cin >> n;
    int ans = 8;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (st.find(x) == st.end())
        {
            // cout << "x: " << x << endl;
            ans++;
        }
    }
    cout << ans << endl;
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