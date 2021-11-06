// https://www.codechef.com/CSNS21B/problems/MAXDMGE
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
    cin >> n;
    vi arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        if (i > 0)
        {
            val = max(val, arr[i] & arr[i - 1]);
        }
        if (i < n - 1)
        {
            val = max(val, arr[i] & arr[i + 1]);
        }
        cout << val << " ";
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