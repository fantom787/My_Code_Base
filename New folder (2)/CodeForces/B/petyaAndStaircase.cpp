#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> dir(m);
    for (int i = 0; i < m; i++)
    {
        cin >> dir[i];
    }
    if (!m)
    {
        cout << "YES" << endl;
        return 0;
    }
    sort(dir.begin(), dir.end());
    if (dir.front() == 1 || dir.back() == n)
    {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < m - 2; i++)
    {
        if (dir[i + 2] == dir[i] + 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}