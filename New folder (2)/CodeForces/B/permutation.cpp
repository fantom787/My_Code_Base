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
    ll n, k;
    cin >> n >> k;
    vector<int> ans(2 * n);
    ll t = n - 2 * k;
    ll p = 0;
    for (int i = 0; i < 2 * k; i++)
    {
        p++;
        ans[i] = i + 1;
    }
    for (int i = 2 * n - 1; i >= 2 * k; i--)
    {
        p++;
        ans[i] = p;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}