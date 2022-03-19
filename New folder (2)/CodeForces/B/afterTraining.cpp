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
    int n, m;
    cin >> n >> m;
    int val = (m + 1) >> 1;
    vector<int> ans(m + 10);
    for (int i = 0; i < m; i++)
    {
        if (m & 1)
        {
            if ((i & 1) == 0)
            {
                val += i;
                ans[i] = val;
            }
            else
            {
                val -= i;
                ans[i] = val;
            }
        }
        else
        {
            if ((i & 1) == 0)
            {
                val -= i;
                ans[i] = val;
            }
            else
            {
                val += i;
                ans[i] = val;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i % m] << " ";
    }
    cout << endl;
    return 0;
}
/*
1 2 3 4 5
_ _ _ _ _
1 3
2 2
3 4
4 1
5 5
    1 2 3 4
    _ _ _ _
    1 2
    2 3
    3 1
    4 4
    _ _ _
    1 2
    2 1
    3 3
    4 2
    5 1
    6 3
    7 2
    8 1
    9
    */