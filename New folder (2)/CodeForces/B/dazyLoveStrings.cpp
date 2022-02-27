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
    int k;
    cin >> k;
    vector<int> wt(26);
    for (int i = 0; i < 26; i++)
    {
        cin >> wt[i];
    }
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        ans += wt[s[i] - 'a'] * (i + 1);
    }
    int maxi = accumulate(wt.begin(), wt.end(), INT_MIN, [](int a, int b)
                          { return max(a, b); });
    ans += ((k * (k + 1) / 2) + n * k) * maxi;
    cout<<ans<<endl;
    return 0;
}