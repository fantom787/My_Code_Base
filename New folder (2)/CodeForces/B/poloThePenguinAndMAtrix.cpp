#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> src;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            src.push_back(x);
        }
    }
    bool flag = true;
    int nSrc = src.size();
    for (int i = 0; i < nSrc; i++)
    {
        if (abs(src[0] - src[i]) % d)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(src);
        int s = 0;
        int e = nSrc - 1;
        int ans = INT_MAX;

        while (s <= e)
        {
            int t1 = 0;
            int t2 = 0;
            int mid1 = (e - s) / 2 + s;
            int mid2 = 2 * ((e - s) / 3) + s;

            for (int i = 0; i < nSrc; i++)
            {
                t1 += (abs(src[i] - src[mid1]) / d);
                t2 += (abs(src[i] - src[mid2]) / d);
            }

            /*
             for (int i = 0; i < n; i++)
             {
                 for (int j = 0; j < m; j++)
                 {
                     t1 += (abs(matrix[i][j] - src[mid1]) / d);
                     t2 += (abs(matrix[i][j] - src[mid2]) / d);
                 }
             }
             */
            ans = min(ans, min(t1, t2));
            if (t1 >= t2)
            {
                s = mid1 + 1;
            }
            else
            {
                e = mid2 - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}