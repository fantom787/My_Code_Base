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
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x].insert(y);
        mp[y].insert(x);
    }
    int ans = 0;
    bool f1 = true;
    while (f1)
    {
        f1 = false;
        unordered_map < int, int > st;
        for (auto it : mp)
        {
            if (it.second.size() == 1)
            {
                st[it.first] = *it.second.begin();
            }
        }
        if (st.size() > 0)
        {
            ans++;
            f1 = true;
            for (auto it : st)
            {
                mp[it.first].erase(it.second);
                mp[it.second].erase(it.first);
            }
        }
    }
    cout << ans << endl;
    return 0;
}