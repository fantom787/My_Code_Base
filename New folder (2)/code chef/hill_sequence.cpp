// https://www.codechef.com/NOV21B/problems/HILLSEQ

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
    int n, pos = 0;
    vi ans;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    for (auto i : m)
    {
        if (i.second > 2)
        {
            pos = 1;
            break;
        }
        ans.push_back(i.first);
    }
    if (pos == 1 || m[ans[ans.size() - 1]] == 2)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (m[ans[i]] == 2)
            {
                cout << ans[i] << " ";
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
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