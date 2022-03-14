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
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    int ans = 0;
    for (auto it : t)
    {
        if (mp.find(it) != mp.end())
        {
            if (mp[it])
            {
                mp[it]--;
                ans++;
            }
        }
        else
        {
            ans = 0;
            break;
        }
    }
    cout << (ans == 0 ? -1 : ans) << endl;
    return 0;
}