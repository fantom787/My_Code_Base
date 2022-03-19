#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

bool dfs(int st, int end, vector<bool> &vis, map<int, set<int>> &grp)
{
    vis[st] = true;
    if (st == end)
    {
        return true;
    }
    for (auto it : grp[st])
    {
        if (!vis[it])
        {
            if (dfs(it, end, vis, grp))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    map<int, set<int>> grp;
    vector<pair<int, int>> data;
    cin >> n;
    while (n--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            int nn = data.size();
            for (int i = 0; i < nn; i++)
            {
                int a = data[i].first;
                int b = data[i].second;
                if (a < x && x < b || a < y && y < b)
                {
                    grp[nn].insert(i);
                }
                if (x < a && a < y || x < b && b < y)
                {
                    grp[i].insert(nn);
                }
            }
            data.push_back({x, y});
        }
        else
        {
            x--;
            y--;
            int nn = data.size();
            vector<bool> vis(nn+1, false);
            if (dfs(x, y, vis, grp))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}