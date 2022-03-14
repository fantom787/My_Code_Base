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
    int v;
    cin >> v;
    vector<int> number(9);
    int mini = INT_MAX;
    int minVal = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> number[i];
        if (mini >= number[i])
        {
            minVal = i + 1;
            mini = number[i];
        }
    }
    int len = v / mini;
    if (!len)
    {
        cout << -1 << endl;
        return 0;
    }
    string ans;
    int rem = v % mini;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 8; i >= minVal; i--)
        {
            if (rem + mini >= number[i])
            {
                ans += ('0' + i + 1);
                rem -= (number[i] - mini);
                len--;
                flag = true;
                break;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        ans += ('0' + minVal);
    }
    cout << ans << endl;

    return 0;
}