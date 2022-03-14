#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    string s;
    int n;
    cin >> n >> s;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && s[i] == s[i + 1])
        {
            time += 1;
            i++;
        }
        else
        {
            time += 1;
        }
    }
    cout << time << endl;
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
