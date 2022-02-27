#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    int odd = 0;
    for (auto it : mp)
    {
        if (it.second % 2)
            odd++;
    }
    if (odd % 2 || !odd)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }

    return 0;
}