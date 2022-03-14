#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    vector<int> ans(n);
    for (int i = n - 1; i > 0; i--)
    {
        int pos = find(all(arr), i + 1) - begin(arr);
        int shift = (pos + 1) % (i + 1);
        ans[i] = shift;
        rotate(begin(arr), begin(arr) + shift, begin(arr) + i + 1);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}