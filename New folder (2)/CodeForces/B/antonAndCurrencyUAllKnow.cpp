#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    string ans = "-1";
    for (int i = 0; i < n; i++)
    {
        if (int(s[i]) % 2 == 0)
        {
            if (int(s[i]) >  int(s[n - 1]))
            {
                swap(s[i], s[n - 1]);
                ans = s;
                swap(s[i], s[n - 1]);
            }
            else
            {
                swap(s[i], s[n - 1]);
                cout << s << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}