#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m;
    map<int, set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    int cnt = 0;
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            for (int k = 1; k < 6; k++)
            {
                if (i != j and j != k and k != i)
                {
                    auto x = mp[i].find(j);
                    auto y = mp[j].find(k);
                    auto z = mp[k].find(i);
                    if (((x != mp[i].end()) && (y != mp[j].end()) && (z != mp[k].end())) || ((x == mp[i].end()) && (y == mp[j].end()) && (z == mp[k].end())))
                    {
                        cout << "WIN" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "FAIL" << endl;
    return 0;
}