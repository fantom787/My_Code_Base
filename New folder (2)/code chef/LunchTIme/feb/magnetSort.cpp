#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(s) s.begin(), s.end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    if (is_sorted(all(a)))
    {
        cout << 0 << endl;
        return;
    }
    int cnt = 0;
    for (auto it : s)
    {
        if (it == 'N')
        {
            cnt++;
        }
    }
    if (cnt == n || !cnt)
    {
        cout << -1 << endl;
        return;
    }
    int first = INT_MAX;
    int last = INT_MIN;
    vector<int> b = a;
    sort(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            first = min(first, i);
            last = max(last, i);
        }
    }
    bool f1 = false, f2 = false;
    for (int i = 0; i < first; i++)
    {
        if (s[i] != s[last])
            f1 = true;
    }
    for (int i = last; i < n; i++)
    {
        if (s[i] != s[first])
            f2 = true;
    }
    if (s[first] != s[last] || f1 || f2)
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }
    cout << endl;
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
