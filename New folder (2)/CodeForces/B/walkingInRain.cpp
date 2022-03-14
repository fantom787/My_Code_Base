#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }
    int ans = min(a[0], a[n - 1]);
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, max(a[i], a[i + 1]));
    }
    cout << ans << endl;
    return 0;
}