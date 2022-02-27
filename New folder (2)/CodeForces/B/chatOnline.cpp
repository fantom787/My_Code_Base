#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<pair<int, int>> p1(p), p2(q);
    for (int i = 0; i < p; i++)
    {
        cin >> p1[i].first >> p1[i].second;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> p2[i].first >> p2[i].second;
    }
    int ans = 0;
    for (int i = l; i < r + 1; i++)
    {
        bool flag = false;
        for(int j=0)
        if(flag)ans++;
    }
    cout << ans << endl;
    return 0;
}