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
    int n, d, l;
    cin >> n >> d >> l;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (!(i & 1))
        {
            ans[i] = l;
        }
        else
        {
            ans[i] = 1;
        }
    }
    int maxAns = 0;
    for (int i = n - 1; i > -1; i--)
    {
        maxAns = ans[i] - maxAns;
    }
    if (d > maxAns)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (maxAns>d)
        {
            if (i & 1)
            {
                ans[i] += min(maxAns - d, l - 1);
                maxAns -= ans[i] - 1;
            }
            else
            {
                ans[i] -= min(maxAns - d, l - 1);
                maxAns -= (l - ans[i]);
            }
        }
    }
    if (maxAns != d)
    {
        cout << -1 << endl;
        return 0;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}