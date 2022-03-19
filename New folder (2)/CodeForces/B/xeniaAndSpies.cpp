#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, st, end;
    cin >> n >> m >> st >> end;
    string ans;
    int tt = 0;
    vector<vector<int>> mat(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        int t, lt, rt;
        cin >> t >> lt >> rt;
        mat[i][0] = t;
        mat[i][1] = lt;
        mat[i][2] = rt;
    }
    int i = 0;
    while (i < m)
    {
        int t, lt, rt;
        t = mat[i][0];
        lt = mat[i][1];
        rt = mat[i][2];
        tt++;
        i++;
        while (tt < t)
        {
            tt++;
            if (st == end)
            {
                cout << ans << endl;
                return 0;
            }
            else if (st > end)
            {
                ans += 'L';
                st--;
            }
            else if (st < end)
            {

                ans += 'R';
                st++;
            }
        }
        if (st == end)
        {
            cout << ans << endl;
            return 0;
        }
        else if (st > end)
        {
            if ((st > rt && st - 1 > rt) || (st < rt && st < lt))
            {
                ans += 'L';
                st--;
            }
            else
            {
                ans += 'X';
            }
        }
        else if (st < end)
        {
            if ((st < lt && st + 1 < lt) || (lt < st && rt < st))
            {
                ans += 'R';
                st++;
            }
            else
            {
                ans += 'X';
            }
        }
    }
    while (st != end)
    {
        if (st == end)
        {
            cout << ans << endl;
            return 0;
        }
        else if (st > end)
        {
            ans += 'L';
            st--;
        }
        else if (st < end)
        {

            ans += 'R';
            st++;
        }
    }
    cout << ans << endl;
    return 0;
}