#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ht(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ht[i];
    }
    int ans = 1;
    int k = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        bool f2 = false;
        bool f1 = false;
        j = i;
        k = i;
        while (j + 1 < n && !f1)
        {
            if (ht[j] < ht[j + 1])
            {
                f1 = true;
            }
            else
            {

                j++;
            }
        }
        while (k - 1 >= 0 && !f2)
        {
            if (ht[k] < ht[k - 1])
            {
                f2 = true;
                break;
            }
            else
            {
                k--;
            }
        }
        ans = max(ans, j - k + 1);
    }
    cout << ans << endl;

    return 0;
}