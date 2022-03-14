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
    unordered_map<char, string> mp;
    mp['>'] = "1000";
    mp['<'] = "1001";
    mp['+'] = "1010";
    mp['-'] = "1011";
    mp['.'] = "1100";
    mp[','] = "1101";
    mp['['] = "1110";
    mp[']'] = "1111";
    string p;
    cin >> p;
    string ans;
    for (auto it : p)
    {
        ans += mp[it];
    }
    reverse(ans.begin(), ans.end());
    ll x = 1;
    ll mod = 1000003;
    ll intAns = 0;
    for (auto it : ans)
    {
        if (it == '1')
        {
            intAns = (intAns + x) % mod;
        }
        x <<= 1;
        x = x % mod;
    }
    cout << intAns << endl;
    return 0;
}