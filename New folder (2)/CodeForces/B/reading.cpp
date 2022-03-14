#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> lit(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        lit[i] = {x, i + 1};
    }
    sort(lit);
    int idx = n - k;
    cout << lit[idx].first << endl;
    for (int i = idx; i < n; i++)
    {
        cout << lit[i].second << " ";
    }
    cout << endl;

    return 0;
}
