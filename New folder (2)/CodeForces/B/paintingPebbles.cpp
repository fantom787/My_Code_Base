#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void display(vector<vector<int>> vec)
{
    for (auto it : vec)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> pebble(n);
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> pebble[i];
        mini = min(mini, pebble[i]);
    }
    mini++;
    vector<vector<int>> ans(n);

    for (int i = 0; i < n; i++)
    {
        int need = max(0, (pebble[i] - mini));
        if (need > k - 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = 0; j < min(mini, pebble[i]); j++)
        {
            ans[i].push_back(1);
        }
        if (need)
        {
            int k = 2;
            for (int j = 0; j < need; j++)
            {
                ans[i].push_back(k++);
            }
        }
    }
    cout << "YES" << endl;
    display(ans);

    return 0;
}