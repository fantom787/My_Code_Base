#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int lowBit(int n)
{
    int ans = 1;
    while (!(n & ans))
    {
        ans <<= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum, limit;
    cin >> sum >> limit;
    vector<int> ans;
    for (int i = limit; i > 0; i--)
    {
        if (!sum)
        {
            break;
        }
        int lb = lowBit(i);
        if (lb <= sum)
        {
            ans.push_back(i);
            sum -= lb;
        }
    }
    if (sum)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}