#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!x)
            cnt++;
    }
    cout << max(cnt, n - cnt) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}
/*
Div 2-B
Print maximum between count of zeros and length of array -count of zeros
*/