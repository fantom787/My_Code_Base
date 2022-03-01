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
    string input;
    cin >> input;
    unordered_map<char, int> mp;
    for (auto it : input)
    {
        mp[it]++;
    }
    string ans;
    int count4 = mp['4'];
    int count7 = mp['7'];
    // cout << "count4: " << count4 << "count7: " << count7 << endl;
    if (!count4 && !count7)
    {
        cout << -1 << endl;
        return 0;
    }
    else if (count4 > count7)
    {
        cout << 4 << endl;
    }
    else if (count4 < count7)
    {
        cout << 7 << endl;
    }
    else
    {
        cout << 4 << endl;
    }
    return 0;
}