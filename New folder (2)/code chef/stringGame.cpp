// https://www.codechef.com/START17B/problems/STRADJ
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt0++;
        if (s[i] == '1')
            cnt1++;
    }
    if (min(cnt0, cnt1) == 0)
    {
        cout << "Bob"
             << "\n";
    }
    else if (min(cnt0, cnt1) == 1)
    {
        cout << "Alice "
             << "\n";
    }
    else
    {
        if (n % 2)
        {
            cout << "Alice "
                 << "\n";
        }
        else
        {
            cout << "Bob"
                 << "\n";
        }
    }
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