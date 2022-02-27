#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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
    int ans = (2 * n) - 1+ht[0];
    for (int i = 0; i < n - 1; i++)
    {
        ans += (abs(ht[i] - ht[i + 1]));
    }
    cout << ans << endl;

    return 0;
}