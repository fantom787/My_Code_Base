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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = k; i < n; i++)
    {
        a[i] += a[i - k];
    }
    int val = INT_MAX;
    int ans = -1;
    for (int i = n - 1; i >= n - k; i--)
    {
        if (a[i] <= val)
        {
            val = a[i];
            ans = i;
        }
    }
    ans++;
    ans %= k;
    if (!ans)
    {
        ans = k;
    }
    cout << ans << endl;

    return 0;
}