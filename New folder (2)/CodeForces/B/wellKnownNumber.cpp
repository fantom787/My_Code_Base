#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, k;
    cin>>s>>k;
    vector<int> cnt(1000);
    int i = 0;
    cnt[0] = 1;
    while (1)
    {
        if (cnt[i] > s)
        {
            break;
        }
        i++;
        for (int j = max(0, i - k); j < i; j++)
        {
            cnt[i] += cnt[j];
        }
    }
    vector<int> ans;
    ans.pb(0);
    for (int j = i; j > -1; j--)
    {
        if (cnt[j] <= s)
        {
            ans.pb(cnt[j]);
            s -= cnt[j];
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}