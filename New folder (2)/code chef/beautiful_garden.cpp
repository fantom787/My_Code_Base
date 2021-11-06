https://www.codechef.com/problems/BEAUTGAR
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
    string s;
    int r = 0;
    int beautiful = 0;
    cin >> s;
    if (s.length() == 1)
    {
        cout << "yes" << endl;
    }
    else if (s.length() % 2)
    {
        cout << "no" << endl;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
            {
                r++;
            }
            if (s[i] == s[(i + 1) % s.length()])
            {
                beautiful++;
            }
        }
        if (beautiful == 0 || (r + r == s.length() && beautiful == 2))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
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