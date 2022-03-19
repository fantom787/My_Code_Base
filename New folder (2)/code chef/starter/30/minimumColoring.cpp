#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m));
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    ans[x1][y1] = 1;
    ans[x2][y2] = 2;
    bool ischess = ((x1 + y1) & 1) != ((x2 + y2) & 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == x1 && j == y1 || i == x2 && j == y2)
            {
                continue;
            }
            if (((i + j) & 1) == ((x1 + y1) & 1))
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = (ischess ? 2 : 3);
            }
        }
    }
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
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