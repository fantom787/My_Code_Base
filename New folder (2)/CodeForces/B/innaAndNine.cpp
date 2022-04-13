#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7
#define ppc __builtin_popcount
#define ppcll _builtin_popcount
#define sz(x) (int)x.size()

int cti(char c)
{
    return (c - '0');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    ll ans = 0;
    int n = sz(s);
    int i = 0;
    int j = 0;
    while (j < n-1)
    {
        if (cti(s[j]) + cti(s[j + 1]) == 9)
        {
            j++;
        }
        else
        {
            j++;
            i = j;
        }
        if (j - i + 1 > 2)
        {
            // cout << "j: " << j << " i" << i << endl;
            ans += pow(2, j - i - 1);
        }
    }
    if (!ans)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}