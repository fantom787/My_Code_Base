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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }
    if (n < 3)
    {
        cout << n << endl;
        return 0;
    }
    bool flag = false;
    int ans = 2;
    int maxlen = 2;
    for (int i = 2; i < n; i++)
    {
        if (a[i] == a[i - 1] + a[i - 2])
        {
            if (flag)
            {
                maxlen++;
            }
            else
            {
                flag = true;
                maxlen++;
            }
        }
        else
        {
            flag = false;
            maxlen = 2;
        }
        ans = max(ans, maxlen);
    }
    cout << ans << endl;

    return 0;
}